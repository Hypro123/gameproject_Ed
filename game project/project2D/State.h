#pragma once
#include "Renderer2D.h"

class StateMachine;

class State
{
public:
	State() {};
	~State() {};


	//This reloads everything everytime something is initialised within it
	virtual void OnEnter() = 0;
	
	//This runs everything that must be run during run time
	virtual void OnUpdate(float fDeltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer) = 0;
	
	//Draws everything at the correct moment for each state
	virtual void OnDraw(aie::Renderer2D* m_2dRenderer) = 0;
	
	//Acts as a deconstructor
	virtual void OnExit() = 0;
};

