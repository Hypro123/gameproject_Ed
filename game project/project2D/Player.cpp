#include "Player.h"
#include "Renderer2D.h"
#include "Input.h"
#include<iostream>
#include <Math.h>
#include"VectorCast.h"
#include"ObjectPool.h"
#include"Bullet.h"

using namespace aie;

#define SPEED 300.0f
#define DRAG 0.5f
#define MASS 1.0f
#define ROTSPEED 10

Player::Player()
{
	this->setTag(PLAYER);
	
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<Texture>::getInstance();
	m_shipTexture = m_pResourceMan->LoadResource("./textures/Fighter.png");

	rotSpeed = ROTSPEED;
	speed = SPEED;
	mass = MASS;
	drag = DRAG;
	
	//Collisions
	ColW = m_shipTexture->getWidth();
	ColH = m_shipTexture->getHeight();
	setDimensions(ColW, ColH);
	SATbase::GetInstance()->CreateObject(this);

	//creates objectpool
	objectpool = new ObjectPool(50);
}


Player::~Player()
{
	delete m_shipTexture;
	delete objectpool;
}

void Player::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setCameraPos(global_Transform[2][0] - 640, global_Transform[2][1] - 360);
	m_2dRenderer->begin();

	Input* input = Input::getInstance();
	
	m_2dRenderer->drawSpriteTransformed3x3(m_shipTexture, global_Transform, 0.0f, 0.0f, -1);

	objectpool->draw(m_2dRenderer);
}

void Player::update(float deltaTime)
{	
	// input example
	Input* input = Input::getInstance();
	Vector2 PrevPos = GetPosition();
	Vector3 direction;
	Matrix3 temp;
	float rot = 0;
	Matrix3 tempRotation;
	float speedCheck = 0;
	//----------------------------------------------
	//Teleport to spawn
	//----------------------------------------------

	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		local_Transform.setPosition(0.0f, 0.0f);
	}

	//----------------------------------------------
	//Movement Forward
	//----------------------------------------------
	
	if (input->isKeyDown(INPUT_KEY_W) || input->isKeyDown(INPUT_KEY_UP))
		direction = global_Transform[1];
	
	//----------------------------------------------
	//Movement Bakcwards
	//----------------------------------------------

	if (input->isKeyDown(INPUT_KEY_S) || input->isKeyDown(INPUT_KEY_DOWN))
		direction = -global_Transform[1];
	
	//----------------------------------------------
	//Movement Left Drift
	//----------------------------------------------

	if (input->isKeyDown(INPUT_KEY_Q))
		direction = -global_Transform[0];
	
	//----------------------------------------------
	//Movement Right Drift
	//----------------------------------------------

	if (input->isKeyDown(INPUT_KEY_E))
		direction = global_Transform[0];

	//----------------------------------------------
	//Rotation Left
	//----------------------------------------------

	if (input->isKeyDown(INPUT_KEY_A) || input->isKeyDown(INPUT_KEY_LEFT))
		rot = rotSpeed * deltaTime;
	
	//----------------------------------------------
	//Rotation Right
	//----------------------------------------------

	if (input->isKeyDown(INPUT_KEY_D) || input->isKeyDown(INPUT_KEY_RIGHT))
		rot -= rotSpeed * deltaTime;
	
	//----------------------------------------------
	//Shoot bullets
	//----------------------------------------------

	if(input->wasKeyPressed(INPUT_KEY_1))
	{
		Bullet* projectile = objectpool->Allocate();
		if (projectile)
		{
			projectile->local_Transform.setPosition(global_Transform.getPosition());
			projectile->dir = CastTo<Vector2>(global_Transform[1]);
		}
		rotSpeed = 2.0f;
	}
	else
	{
		rotSpeed = ROTSPEED;
	}
	
	//----------------------------------------------
	//Shoots Bullets Around Player
	//----------------------------------------------

	if(input->wasKeyPressed(INPUT_KEY_2))
	{
		for(int i = 0; i < 16; i++)
		{
			Bullet* projectile = objectpool->Allocate();
			if (projectile)
				{
				float angle = (6.28/0.3925) * i;
				
				Vector2 projdir;
				projdir.x = sinf(angle);
				projdir.y = -cosf(angle);
				
				projectile->local_Transform.setPosition(global_Transform.getPosition());
				projectile->dir = projdir;
			}
		}
	}

	objectpool->update(deltaTime);

	Vector2 dirV2 = CastTo<Vector2>(direction);
	//ACCELERATION AND DRAG
	Vector2 forceSum = dirV2 * speed;
	Vector2 acceleration = forceSum / mass;
	Vector2 dampening = -(Velocity * drag);
	Velocity += (acceleration + dampening) * deltaTime;

	//ROTATION
	tempRotation.setRotateZ(rot);
	local_Transform = local_Transform * tempRotation;
	
	//MOVEMENT
	temp.setPosition(Velocity * deltaTime);
	local_Transform = temp * local_Transform;

	//----------------------------------------------
	//Blink teleport like ability
	//----------------------------------------------
	if (input->wasKeyPressed(INPUT_KEY_3))
	{
		local_Transform.setPosition(global_Transform.getPosition() + (Velocity * 1.25));
	}

	updateGlobalTransform();

	//----------------------------------------------
	//Collision of Player to Rock
	//----------------------------------------------

	SATbase* pCollision = SATbase::GetInstance();
	Hit rockCollider;
	rockCollider = pCollision->CheckCollisions(this);
	if(rockCollider.ety != nullptr && rockCollider.ety->getTag() == ROCK)
	{
		Velocity = Velocity.bounce(rockCollider.norm * -1);
		temp.setPosition(rockCollider.norm * rockCollider.depth);
		local_Transform = temp * local_Transform;
		
		updateGlobalTransform();
	}
}