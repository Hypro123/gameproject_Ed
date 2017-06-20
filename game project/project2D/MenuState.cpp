#include "MenuState.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "Input.h"

MenuState::MenuState()
{
	ResourceManager<aie::Texture>* rManager = ResourceManager<aie::Texture>::getInstance();

	m_pMenuTexture = rManager->LoadResource("./textures/Map.png");
	m_pTitle = rManager->LoadResource("./textures/Proving_Arena.png");
	m_pStartText1 = rManager->LoadResource("./textures/PtoPlayY.png");
	m_pStartText2 = rManager->LoadResource("./textures/PtoPlayG.png");

	spriteNo = 0;
}


MenuState::~MenuState()
{
	delete m_pMenuTexture;
	delete m_pTitle;
	delete m_pStartText1;
	delete m_pStartText2;
}

void MenuState::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	//spriteCheck += spriteNo;
	m_2dRenderer->drawSprite(m_pMenuTexture, 0.0f, 0.0f, 1280.0f, 720.0f);
	m_2dRenderer->drawSprite(m_pTitle, 0.0f, 70.0f, 0.0f, 0.0f);
	if((int)spriteNo % 2 == 0)
		m_2dRenderer->drawSprite(m_pStartText1, 0.0f, -200.0f, 0.0f, 0.0f);
	else
		m_2dRenderer->drawSprite(m_pStartText2, 0.0f, -200.0f, 0.0f, 0.0f);
}

void MenuState::OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer)
{
	spriteNo += deltaTime;
	
	aie::Input* input = aie::Input::getInstance();
	if(input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
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