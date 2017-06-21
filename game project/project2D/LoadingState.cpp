#include "LoadingState.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include <crtdbg.h>

LoadingState::LoadingState()
{
	ResourceManager<aie::Texture>* m_tLoading = ResourceManager<aie::Texture>::getInstance();
	m_ptexture = m_tLoading->LoadResource("./textures/Map.png");
	m_phelp = m_tLoading->LoadResource("./textures/help.png");
	m_pCircle = new LoadingCircle();
	m_pCircle->local_Transform.setPosition(560, -300);
	timer = 0;

	_ASSERT(m_pCircle);
}


LoadingState::~LoadingState()
{
	delete m_pCircle;
	delete m_phelp;
	delete m_ptexture;
}

void LoadingState::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_ptexture, 0.0f, 0.0f, 1280.0f, 720.0f);
	m_2dRenderer->drawSprite(m_phelp, 0.0f, 0.0f);
	m_pCircle->Draw(m_2dRenderer);
}

void LoadingState::OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer)
{
	timer += deltaTime;
	m_pCircle->Update(deltaTime);

	m_2dRenderer->setCameraPos(-640, -360);

	if (timer > 5)
	{
		pObject->popState();
		pObject->pushState(3);
	}
}

void LoadingState::OnEnter()
{
}

void LoadingState::OnExit()
{
}
