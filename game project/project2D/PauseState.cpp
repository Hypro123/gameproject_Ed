#include "PauseState.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "Input.h"

using namespace aie;

//------------
//Constructor
//------------
PauseState::PauseState()
{
	ResourceManager<aie::Texture>* m_pTexture = ResourceManager<aie::Texture>::getInstance();
	m_pPause = m_pTexture->LoadResource("./textures/help.png");
}

//--------------
//Deconstructor
//--------------
PauseState::~PauseState()
{
	delete m_pPause;
}

void PauseState::OnEnter()
{
}


void PauseState::OnExit()
{
}

//---------------------------------------------------------------------------------------
//Uses the renderer to render the pause screen on top of the already playable game state
//---------------------------------------------------------------------------------------
void PauseState::OnDraw(Renderer2D* m_2dRenderer)
{
	//Sets the camera position to the player's location
	float posx;
	float posy;
	m_2dRenderer->getCameraPos(posx, posy);
	m_2dRenderer->drawSprite(m_pPause, posx + 640, posy + 360);
}

//-------------------------------------------------------
//Updates the Pause screen over frames, checks for input
//-------------------------------------------------------
void PauseState::OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer)
{
	Input* input = Input::getInstance();
	//Checks if the pause button was pressed and whether the game should go back to running
	if (input->wasKeyPressed(INPUT_KEY_P))
	{
		pObject->popState();
		pObject->setRenderBackGround(false);
	}
}