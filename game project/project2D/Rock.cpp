#include "Rock.h"
#include "Renderer2D.h"
#include "SATbase.h"
#include "ResourceManager.h"

using namespace aie;

//------------
//Constructor
//------------
Rock::Rock()
{
	//Uses the Rock texture with the resourceManager
	ResourceManager<Texture>* Rman = ResourceManager<Texture>::getInstance();
	m_rock = Rman->LoadResource("./textures/rock_large.png");
	//Sets the Rock's Tag
	this->setTag(ROCK);

	//gets the actual sprites height and width
	float rockWidth = m_rock->getWidth();
	float rockHeight = m_rock->getHeight();

	//Sets collider dimensions
	setDimensions(rockWidth, rockHeight);
	
	//Draws the rock in the designated position
	local_Transform.setPosition(300.0f, 300.0f);
	
	//Creates an instance of the Collider
	SATbase::GetInstance()->CreateObject(this);
	
	//Updates its position and puts it onto the global transform
	updateGlobalTransform();
}

//--------------
//Deconstructor
//--------------
Rock::~Rock()
{
	delete m_rock;
}

//---------------
//Draws the Rock
//---------------
void Rock::drawRock(Renderer2D* m_2dRenderer)
{
	//updateGlobalTransform();

	m_2dRenderer->drawSpriteTransformed3x3(m_rock, global_Transform);
}
