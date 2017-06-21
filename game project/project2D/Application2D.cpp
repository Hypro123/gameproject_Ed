#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include<iostream>
#include "ResourceManager.h"
#include "SplashState.h"
#include "GameState.h"
#include "LoadingState.h"
#include "MenuState.h"
#include "PauseState.h"

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	ResourceManager<Texture>::create();
	m_2dRenderer = new Renderer2D();

	//State Managment
	pStateMachine = new StateMachine();
	pStateMachine->AddState(0, new SplashState());
	pStateMachine->AddState(1, new MenuState());
	pStateMachine->AddState(2, new LoadingState());
	pStateMachine->AddState(3, new GameState());
	pStateMachine->AddState(4, new PauseState());
	
	_ASSERT(pStateMachine);
	_ASSERT(m_2dRenderer);

	pStateMachine->pushState(0);
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete pStateMachine;
	delete m_2dRenderer;
	ResourceManager<Texture>::destroy();
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	pStateMachine->Update(deltaTime, m_2dRenderer);
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_BACKSPACE))
		quit();
}

void Application2D::draw()
{
	// wipe the screen to the background colour
	clearScreen();
	// begin drawing sprites
	m_2dRenderer->begin();
	pStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->end();
}