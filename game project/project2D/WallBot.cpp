#include "WallBot.h"
#include "SATbase.h"
#include "ResourceManager.h"

using namespace aie;

WallBot::WallBot()
{
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<Texture>::getInstance();

	TBTexture = m_pResourceMan->LoadResource("./textures/TB_WALL.png");
	//------------------------------------------------------------------------------
	//Collisions for the wall to make sure it reacts with the player and the bullets
	//the same way a rock does within the game.
	//------------------------------------------------------------------------------
	
	//Sets the tag
	this->setTag(ROCK);
	
	//Setting the colliders width and height based on the object's texture size
	TW = TBTexture->getWidth();
	TH = TBTexture->getHeight();
	
	//Actually sets the dimensions of the collider
	setDimensions(TW, TH);

	//Gets an instance of the SAT collider and creates the actual collider for the object
	SATbase::GetInstance()->CreateObject(this);
	
	//Sets the local transform of the bottom wall and updates the global transform 
	local_Transform.setPosition(0, -2048);
	updateGlobalTransform();
}

//-----------------------------------------------------------
//Deletes the object's texture when its done with the texture
//-----------------------------------------------------------

WallBot::~WallBot()
{
	// Texture of the object gets deleted
	delete TBTexture;
}

//------------------------------------------
//The draw function
//------------------------------------------

void WallBot::draw(Renderer2D* m_2dRenderer)
{
	//Draws the Wall on with world
	m_2dRenderer->drawSpriteTransformed3x3(TBTexture, global_Transform);
}