#include "Bullet.h"
#include"VectorCast.h"
#include"SATbase.h"
#include "ResourceManager.h"

//Speed is defined so that the number is not required to be remembered
#define SPEED 200
//for damage, does not work was added in for testing
#define DMG 5

Bullet::Bullet()
{
	//Sets the speed to a common speed variable
	m_fspeed = SPEED;
	
	//Using the resource Manager in order to make the textures  more efficiant
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<aie::Texture>::getInstance();

	//Loads the textures for the bullet
	bulletTexture = m_pResourceMan->LoadResource("./textures/Bullet.png");
	explosionTexture = m_pResourceMan->LoadResource("./textures/Explode.png");
	//Sets the bullets to be created far away so that they do not disrupt the gameflow
	local_Transform.setPosition(99999,99999);

	//makes this tag set as bullet so that objects know how to interact with it
	this->setTag(BULLET);

	//Initialising variables
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
	//Cleans up floating pointers
	delete bulletTexture;
	delete explosionTexture;
}

void Bullet::draw(aie::Renderer2D* m_2dRenderer)
{	
	//Decides which texture to draw the bullet with, exploaded or not
	if (m_ftimer >= 5 || collided)
		m_2dRenderer->drawSpriteTransformed3x3(explosionTexture, local_Transform, 0.0f, 0.0f, -0.2);
	else if(!collided)
		m_2dRenderer->drawSpriteTransformed3x3(bulletTexture, local_Transform, 0.0f, 0.0f, -0.1);
}

void Bullet::update(float deltaTime)
{
	//Makes the bullet move
	Matrix3 temp;
	temp.setPosition(dir * m_fspeed * deltaTime);
	local_Transform = temp * local_Transform;
	
	//increments timer
	m_ftimer += deltaTime;
	
	if (m_ftimer >= 5)
		m_fspeed = 0;

	//hides the bullet for later use after the timer has run out
	if (m_ftimer >= 6)
	{
		m_bActive = false;
		m_fspeed = SPEED;
		m_ftimer = 0;
	}
	//Updates global position of the player
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
			//Does the explosion texture after a certain period of time
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

	//--------------------------------------------------------------------------------------
	//This was done as a test to see if bullets could collide with another object that uses 
	//the "Player tag" so that you can bounce the bullet accross multiple players.
	//This had no practicle use, this was just playing around within ideas.
	//--------------------------------------------------------------------------------------

	////Collision bullet to Player
	//SATbase* pCollision1 = SATbase::GetInstance();
	//Hit rockCollider1;
	//rockCollider1 = pCollision1->CheckCollisions(this);
	//if (rockCollider1.ety != nullptr && rockCollider1.ety->getTag() == PLAYER)
	//{
	//	//Bouncing bullets
	//	dir = dir.bounce(rockCollider1.norm * -1);
	//	temp.setPosition(rockCollider1.norm * rockCollider1.depth);
	//	local_Transform = temp * local_Transform;
	//}

	//if(collided)
	//{
	//	colTimer += deltaTime;
	//}
	updateGlobalTransform();
}


//-----------------------------------------------------------------------------------------------------
//This Makes the bullet active or inactive and is used in order to keep the m_bActive Variable private
//-----------------------------------------------------------------------------------------------------
void Bullet::setActive(bool bActive)
{
	m_bActive = bActive;
}
//The Getter function can be used outside of this function so that Gameobjects can see whether the bullet is active or not
bool Bullet::GetActive()
{
	return m_bActive;
}

