#include "SplashState.h"
#include "ResourceManager.h"
#include "StateMachine.h"


//------------
//Constructor
//------------
SplashState::SplashState()
{
	//Uses the resource Manager for more efficiant use of the textures
	ResourceManager<aie::Texture>* m_tSplashScreen = ResourceManager<aie::Texture>::getInstance();

	//Loads the textures
	m_ptexture = m_tSplashScreen->LoadResource("./textures/Map.png");
	m_title = m_tSplashScreen->LoadResource("./textures/Proving_Arena.png");
	
	//initialises this so that random large or small numbers are not called
	timer = 0;
}

//--------------
//Deconstructor
//--------------
SplashState::~SplashState()
{
	delete m_ptexture;
	delete m_title;
}

//------------------------
//Draws both the textures
//------------------------
void SplashState::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_ptexture, 0.0f, 0.0f, 1280.0f, 720.0f);
	m_2dRenderer->drawSprite(m_title, 0.0f, 70.0f, 0.0f, 0.0f);
}

//-------------------------------------------
//Updates the Screen for as long as required
//-------------------------------------------
void SplashState::OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer)
{
	timer += deltaTime;

	m_2dRenderer->setCameraPos(-640, -360);

	if (timer > 3)
	{
		//calls on the next state by poping off this state
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