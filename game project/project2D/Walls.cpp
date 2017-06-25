#include "Walls.h"
#include "SATbase.h"
#include "ResourceManager.h"

using namespace aie;

//------------
//Constructor
//------------
Walls::Walls()
{
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<Texture>::getInstance();
	//Loads the walls textures
	TBTexture = m_pResourceMan->LoadResource("./textures/TB_WALL.png");

	//Collisions
	//Makes the wall act as a wall so that players interact with it the same way
	this->setTag(ROCK);
	//gets the textures dimensions
	TW = TBTexture->getWidth();
	TH = TBTexture->getHeight();
	//Sets the collider's dimensions
	setDimensions(TW, TH);
	//Change it's position to be in the correct place
	local_Transform.setPosition(0, 2048);

	//Creates an instance of the collider
	SATbase::GetInstance()->CreateObject(this);
	//Updates the global position
	updateGlobalTransform();
}

//--------------
//Deconstructor
//--------------
Walls::~Walls()
{
	delete TBTexture;
}

//---------------
//Draws the Wall
//---------------
void Walls::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(TBTexture, global_Transform);
}
