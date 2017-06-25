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
	//Constructor and deconstructor
	GameState();
	~GameState();

	//Starts everything in here when the game starts
	void OnEnter();

	//Runs this function when required and updates the objects and such in the state
	void OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer);

	//Draws the state and everything contained within it
	void OnDraw(aie::Renderer2D* m_2dRenderer);

	//Runs this when the state ends
	void OnExit();
	
	//Entities
	Rock* rock;
	Player* player;
	Walls* walltop;
	WallBot* wallbot;
	WallLeft* wallleft;
	WallRight* wallright;
	
	//Collider
	SATbase* SAT;

private:
	float timer;
};

