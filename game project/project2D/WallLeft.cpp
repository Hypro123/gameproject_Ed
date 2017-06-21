#include "WallLeft.h"
#include "SATbase.h"
#include "ResourceManager.h"

using namespace aie;

WallLeft::WallLeft()
{
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<Texture>::getInstance();

	LRTexture = m_pResourceMan->LoadResource("./textures/LR_WALL.png");

	//------------------------------------------------------------------------------
	//Collisions for the wall to make sure it reacts with the player and the bullets
	//the same way a rock does within the game.
	//------------------------------------------------------------------------------
	
	//Sets the tag
	this->setTag(ROCK);

	//Setting the colliders width and height based on the object's texture size
	LW = LRTexture->getWidth();
	LH = LRTexture->getHeight();
	
	//Sets the dimensions of the Collider
	setDimensions(LW, LH);

	//Gets an instance of the SAT collider and creates a collider object out of this object
	SATbase::GetInstance()->CreateObject(this);
	
	//Sets the local position then applies it to the global location
	local_Transform.setPosition(-2048, 0);
	updateGlobalTransform();
}

//-----------------------------------------------------------
//Deletes the object's texture when its done with the texture
//-----------------------------------------------------------

WallLeft::~WallLeft()
{
	// Texture of the object gets deleted
	delete LRTexture;
}

//------------------------------------------
//The draw function
//------------------------------------------

void WallLeft::draw(Renderer2D* m_2dRenderer)
{
	//Draws the wall in the world
	m_2dRenderer->drawSpriteTransformed3x3(LRTexture, global_Transform);
}
