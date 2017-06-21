#include "WallRight.h"
#include "SATbase.h"
#include "ResourceManager.h"

using namespace aie;

WallRight::WallRight()
{
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<Texture>::getInstance();

	LRTexture = m_pResourceMan->LoadResource("./textures/LR_WALL.png");

	//------------------------------------------------------------------------------
	//Collisions for the wall to make sure it reacts with the player and the bullets
	//the same way a rock does within the game.
	//------------------------------------------------------------------------------

	//Sets the wall's tag
	this->setTag(ROCK);
	
	//getting dimensions of the object's texture
	RW = LRTexture->getWidth();
	RH = LRTexture->getHeight();
	
	//Sets the dimensions of the Collider to be the same as the object's texture
	setDimensions(RW, RH);

	//Gets an instance of the SAT collider and creates the collider object
	SATbase::GetInstance()->CreateObject(this);
	
	//Sets initial position of the right wall and updates the global transform to change it's position globally
	local_Transform.setPosition(2048, 0);
	updateGlobalTransform();
}

//-------------------------------------------------------------------------------------
//Delete's wall's texture after the texture no longer needs to be rendered in the scene
//-------------------------------------------------------------------------------------

WallRight::~WallRight()
{
	delete LRTexture;
}

//-----------------------------
//Draw function
//-----------------------------

void WallRight::draw(Renderer2D* m_2dRenderer)
{
	//Draws the wall in the proper global position specified in the constructor
	m_2dRenderer->drawSpriteTransformed3x3(LRTexture, global_Transform);
}
