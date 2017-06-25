#include "LoadingCircle.h"
#include "ResourceManager.h"


//------------
//Constructor
//------------
LoadingCircle::LoadingCircle()
{
	//Sets a position for the object to be created
	local_Transform.setPosition(560, -300);
	//Uses the resource Manager for the texture
	ResourceManager<aie::Texture>* temp = ResourceManager<aie::Texture>::getInstance();
	//Loads the texture
	m_loadCircle = temp->LoadResource("./textures/Loading.png");
	//Checks for how long the object should spin
	timer = 0;
}

//--------------
//Deconstructor
//--------------
LoadingCircle::~LoadingCircle()
{
}

//----------------
//Update Function
//----------------
void LoadingCircle::Update(float deltaTime)
{
	//Makes the object's timer increment as the game runs
	timer += deltaTime;
}

//--------------
//Draw Function
//--------------
void LoadingCircle::Draw(aie::Renderer2D* m_2dRenderer)
{
	//Draws the Object in different orientations so that it is effectivly spinning
	m_2dRenderer->drawSprite(m_loadCircle, 560, -300, 0.0f, 0.0f, timer * 5);
}