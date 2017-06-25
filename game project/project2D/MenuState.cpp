#include "MenuState.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "Input.h"

//------------
//Constructor
//------------
MenuState::MenuState()
{
	ResourceManager<aie::Texture>* rManager = ResourceManager<aie::Texture>::getInstance();
	//Loads the texture resources
	m_pMenuTexture = rManager->LoadResource("./textures/Map.png");
	m_pTitle = rManager->LoadResource("./textures/Proving_Arena.png");
	m_pStartText1 = rManager->LoadResource("./textures/PtoPlayY.png");
	m_pStartText2 = rManager->LoadResource("./textures/PtoPlayG.png");
	//initialises this variable
	spriteNo = 0;
}

//--------------
//Deconstructor
//--------------
MenuState::~MenuState()
{
	//Deletes unused textures
	delete m_pMenuTexture;
	delete m_pTitle;
	delete m_pStartText1;
	delete m_pStartText2;
}

//-------------------------------------------------------------------------------------------
//This function is responsible for drawing everything in the scene while the state is active
//-------------------------------------------------------------------------------------------
void MenuState::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_pMenuTexture, 0.0f, 0.0f, 1280.0f, 720.0f);
	m_2dRenderer->drawSprite(m_pTitle, 0.0f, 70.0f, 0.0f, 0.0f);
	//Changes the colour(texture) of the "Press space to play button"
	if((int)spriteNo % 2 == 0)
		m_2dRenderer->drawSprite(m_pStartText1, 0.0f, -200.0f, 0.0f, 0.0f);
	else
		m_2dRenderer->drawSprite(m_pStartText2, 0.0f, -200.0f, 0.0f, 0.0f);
}

//---------------------------------------------------------------------------------------------------------------------------------------
//Calls the update function and updates everything in the scene that needs to be updated,eg. whether the player has pressed space or not
//---------------------------------------------------------------------------------------------------------------------------------------
void MenuState::OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer)
{
	//gets deltaTime into this class form the update function
	spriteNo += deltaTime;
	//Waits for player input
	aie::Input* input = aie::Input::getInstance();
	if(input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		//Pushes the next state onto the stack after the condition has been passed
		pObject->popState();
		pObject->pushState(2);
	}
}

void MenuState::OnEnter()
{
}

void MenuState::OnExit()
{
}