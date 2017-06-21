#include "GameState.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Input.h"
#include <crtdbg.h>

using namespace aie;

GameState::GameState()
{
	
	SAT->Create();
	
	rock = new Rock();
	walltop = new Walls();
	wallbot = new WallBot();
	wallleft = new WallLeft();
	wallright = new WallRight();
	player = new Player();

	_ASSERT(rock);
	_ASSERT(walltop);
	_ASSERT(wallbot);
	_ASSERT(wallright);
	_ASSERT(wallleft);
	_ASSERT(player);
}


GameState::~GameState()
{
	delete player;
	delete wallright;
	delete wallleft;
	delete wallbot;
	delete walltop;
	delete rock;
	SAT->Destroy();
}

void GameState::OnEnter()
{
}

void GameState::OnExit()
{
}

void GameState::OnDraw(aie::Renderer2D* m_2dRenderer)
{
	player->draw(m_2dRenderer);
	rock->drawRock(m_2dRenderer);
	walltop->draw(m_2dRenderer);
	wallbot->draw(m_2dRenderer);
	wallleft->draw(m_2dRenderer);
	wallright->draw(m_2dRenderer);
}

void GameState::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	player->update(deltaTime);

	Input* input = Input::getInstance();

	if(input->wasKeyPressed(INPUT_KEY_P))
	{
		pStateMachine->pushState(4);
		pStateMachine->setRenderBackGround(true);
	}
}