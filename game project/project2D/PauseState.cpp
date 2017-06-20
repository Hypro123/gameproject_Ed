#include "PauseState.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "Input.h"

using namespace aie;

PauseState::PauseState()
{
	ResourceManager<aie::Texture>* m_pTexture = ResourceManager<aie::Texture>::getInstance();
	m_pPause = m_pTexture->LoadResource("./textures/help.png");
}


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

void PauseState::OnDraw(Renderer2D* m_2dRenderer)
{
	float posx;
	float posy;
	m_2dRenderer->getCameraPos(posx, posy);
	m_2dRenderer->drawSprite(m_pPause, posx + 640, posy + 360);
}

void PauseState::OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer)
{
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_P))
	{
		pObject->popState();
		pObject->setRenderBackGround(false);
	}
}