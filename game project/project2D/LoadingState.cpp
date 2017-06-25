#include "LoadingState.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include <crtdbg.h>

//------------
//Constructor
//------------
LoadingState::LoadingState()
{
	ResourceManager<aie::Texture>* m_tLoading = ResourceManager<aie::Texture>::getInstance();
	//Loads the textures
	m_ptexture = m_tLoading->LoadResource("./textures/Map.png");
	m_phelp = m_tLoading->LoadResource("./textures/help.png");
	//Creates a new Loading circle object pointer for the scene
	m_pCircle = new LoadingCircle();
	//Sets the position
	m_pCircle->local_Transform.setPosition(560, -300);
	timer = 0;

	//Assert for debugging
	_ASSERT(m_pCircle);
}

//--------------
//Deconstructor
//--------------
LoadingState::~LoadingState()
{
	delete m_pCircle;
	delete m_phelp;
	delete m_ptexture;
}

//--------------------------------------------
//Draws everything in the state while it runs
//--------------------------------------------
void LoadingState::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_ptexture, 0.0f, 0.0f, 1280.0f, 720.0f);
	m_2dRenderer->drawSprite(m_phelp, 0.0f, 0.0f);
	m_pCircle->Draw(m_2dRenderer);
}

//--------------------------------------------------------
//Updates the scene every frame while the state is active
//--------------------------------------------------------
void LoadingState::OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer)
{
	timer += deltaTime;
	m_pCircle->Update(deltaTime);
	//sets the camera position so that it is looking at the full view of the state
	m_2dRenderer->setCameraPos(-640, -360);

	if (timer > 5)
	{
		//Goes onto the next state
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
