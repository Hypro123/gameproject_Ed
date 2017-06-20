#pragma once
#include "State.h"
#include "Player.h"
#include "Rock.h"
#include "Walls.h"
#include "WallBot.h"
#include "WallLeft.h"
#include "WallRight.h"
#include "SATbase.h"

class GameState : public State
{
public:
	GameState();
	~GameState();

	void OnEnter();

	void OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer);

	void OnDraw(aie::Renderer2D* m_2dRenderer);

	void OnExit();
	
	//Entities
	Rock* rock;
	Player* player;
	Walls* wall;
	WallBot* wallbot;
	WallLeft* wallleft;
	WallRight* wallright;
	
	//Collider
	SATbase* SAT;

private:
	float timer;
};

