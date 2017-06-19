#include "LoadingState.h"
#include "ResourceManager.h"

LoadingState::LoadingState()
{
	ResourceManager<aie::Texture>* m_tLoading = ResourceManager<aie::Texture>::getInstance();
	m_ptexture = m_tLoading->LoadResource("./textures/Map.png");
	m_pCircle = new LoadingCircle();

	timer = 0;
}


LoadingState::~LoadingState()
{
	delete m_pCircle;
	delete m_ptexture;
}

void LoadingState::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_ptexture, 0.0f, 0.0f, 1280.0f, 720.0f);
	m_pCircle->Draw(m_2dRenderer);
}

void LoadingState::OnUpdate(float deltaTime, StateMachine* pObject)
{
	timer += deltaTime;
	m_pCircle->Update(deltaTime);

	if (timer > 3)
	{
		pObject->popState();
		pObject->pushState(2);
	}
}

void LoadingState::OnEnter()
{
}

void LoadingState::OnExit()
{
}
