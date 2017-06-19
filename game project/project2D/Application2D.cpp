#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include<iostream>
#include "ResourceManager.h"
#include "SplashState.h"
#include "LoadingState.h"

using namespace aie;

#define ROW 3
#define COL 3
#define AMOUNT ROW * COL

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	ResourceManager<Texture>::create();
	SAT->Create();
	m_2dRenderer = new Renderer2D();
	rock = new Rock();
	player = new Player();

	//State Managment
	pStateMachine = new StateMachine();
	pStateMachine->AddState(0, new SplashState());
	pStateMachine->AddState(1, new LoadingState());
	
	pStateMachine->pushState(0);
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete pStateMachine;
	delete player;
	delete rock;
	delete m_2dRenderer;
	SAT->Destroy();
	ResourceManager<Texture>::destroy();
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	player->update(deltaTime);
	pStateMachine->Update(deltaTime);
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();
	// begin drawing sprites
	m_2dRenderer->begin();
	player->draw(m_2dRenderer);
	rock->drawRock(m_2dRenderer);
	pStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->end();
}