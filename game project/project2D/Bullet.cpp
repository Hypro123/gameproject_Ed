#include "Bullet.h"
#include"VectorCast.h"
#include"SATbase.h"
#include "ResourceManager.h"

#define SPEED 200
#define DMG 5

Bullet::Bullet()
{
	m_fspeed = SPEED;
	
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<aie::Texture>::getInstance();

	bulletTexture = m_pResourceMan->LoadResource("./textures/Bullet.png");
	explosionTexture = m_pResourceMan->LoadResource("./textures/Explode.png");
	local_Transform.setPosition(99999,99999);

	this->setTag(BULLET);

	m_ftimer = 0;
	colTimer = 0;

	m_bActive = false;

	collided = false;

	//Collisions
	ColW = bulletTexture->getWidth();
	ColH = bulletTexture->getHeight();
	setDimensions(ColW, ColH);
	SATbase::GetInstance()->CreateObject(this);
}


Bullet::~Bullet()
{
	delete bulletTexture;
	delete explosionTexture;
}

void Bullet::draw(aie::Renderer2D* m_2dRenderer)
{	
	if (m_ftimer >= 5 || collided)
		m_2dRenderer->drawSpriteTransformed3x3(explosionTexture, local_Transform, 0.0f, 0.0f, -0.2);
	else if(!collided)
		m_2dRenderer->drawSpriteTransformed3x3(bulletTexture, local_Transform, 0.0f, 0.0f, -0.1);
}

void Bullet::update(float deltaTime)
{
	Matrix3 temp;
	temp.setPosition(dir * m_fspeed * deltaTime);
	local_Transform = temp * local_Transform;
	
	//increments timer
	m_ftimer += deltaTime;
	
	if (m_ftimer >= 5)
		m_fspeed = 0;

	if (m_ftimer >= 6)
	{
		m_bActive = false;
		m_fspeed = SPEED;
		m_ftimer = 0;
	}
	updateGlobalTransform();

	//Collision bullet to rock
	SATbase* pCollision = SATbase::GetInstance();
	Hit rockCollider;
	rockCollider = pCollision->CheckCollisions(this);
	if (rockCollider.ety != nullptr && rockCollider.ety->getTag() == ROCK)
	{
		collided = true;
		m_fspeed = 0;
		if (colTimer >= 1)
		{
			m_fspeed = SPEED;
			m_bActive = false;
			colTimer = 0;
			m_ftimer = 0;
		}
	}
	else
	{
		collided = false;
	}

	//Collision bullet to Player
	SATbase* pCollision1 = SATbase::GetInstance();
	Hit rockCollider1;
	rockCollider1 = pCollision1->CheckCollisions(this);
	if (rockCollider1.ety != nullptr && rockCollider1.ety->getTag() == PLAYER)
	{
		//Bouncing bullets
		dir = dir.bounce(rockCollider1.norm * -1);
		temp.setPosition(rockCollider1.norm * rockCollider1.depth);
		local_Transform = temp * local_Transform;
	}

	if(collided)
	{
		colTimer += deltaTime;
	}
	updateGlobalTransform();
}


void Bullet::setActive(bool bActive)
{
	m_bActive = bActive;
}

bool Bullet::GetActive()
{
	return m_bActive;
}

