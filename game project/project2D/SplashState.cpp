#include "SplashState.h"
#include "ResourceManager.h"
#include "StateMachine.h"

SplashState::SplashState()
{
	ResourceManager<aie::Texture>* m_tSplashScreen = ResourceManager<aie::Texture>::getInstance();

	m_ptexture = m_tSplashScreen->LoadResource("./textures/Map.png");
	m_title = m_tSplashScreen->LoadResource("./textures/Proving_Arena.png");
	timer = 0;
}


SplashState::~SplashState()
{
	delete m_ptexture;
	delete m_title;
}


void SplashState::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_ptexture, 0.0f, 0.0f, 1280.0f, 720.0f);
	m_2dRenderer->drawSprite(m_title, 0.0f, 70.0f, 0.0f, 0.0f);
}

void SplashState::OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer)
{
	timer += deltaTime;

	m_2dRenderer->setCameraPos(-640, -360);

	if (timer > 3)
	{
		pObject->popState();
		pObject->pushState(1);
	}
}

void SplashState::OnEnter()
{
}

void SplashState::OnExit()
{
}