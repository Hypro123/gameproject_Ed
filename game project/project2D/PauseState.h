#pragma once
#include "State.h"
#include "Texture.h"

using namespace aie;

class PauseState : public State
{
public:
	//Constructor and deconstructor
	PauseState();
	~PauseState();
	
	//Does something when the state is first called
	void OnEnter();
	//DOes something when the state is popped off
	void OnExit();

	//Draws the state
	void OnDraw(Renderer2D* m_2dRenderer);
	//Updates the state over a certain period of time ot till a certain condition is fulfilled
	void OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);

	//The pause screen texture pointer
	Texture* m_pPause;
};

