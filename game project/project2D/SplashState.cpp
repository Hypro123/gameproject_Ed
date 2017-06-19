#include "SplashState.h"
#include "ResourceManager.h"

SplashState::SplashState()
{
	ResourceManager<aie::Texture>* m_tSplashScreen = ResourceManager<aie::Texture>::getInstance();
	m_ptexture = m_tSplashScreen->LoadResource("./textures/Map.png");
	timer = 0;
}


SplashState::~SplashState()
{
	delete m_ptexture;
}


void SplashState::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_ptexture, 0.0f, 0.0f, 1280.0f, 720.0f);
}

void SplashState::OnUpdate(float deltaTime, StateMachine* pObject)
{
	timer += deltaTime;

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