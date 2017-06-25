#pragma once
#include "DynamicArray.h"
#include "State.h"
#include "Stack.h"



class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	//Updates all functions within it;
	void Update(float fDeltaTime, aie::Renderer2D* m_2dRenderer);
	//Adds a new state to the StateMachine
	void AddState(int nStateIndex, State* pState);
	//Draws the State
	void Draw(aie::Renderer2D* m_2dRenderer);
	//Pushes the next state to the top of the stack
	void pushState(int nStateIndex);
	//Pops the state off the stack
	void popState();
	//Checks wether the background should be rendered or not
	void setRenderBackGround(bool RenderBackground);
private:
	//Private boolean should not be changed
	bool m_bRenderBackground;
	
	//Array of the states and a pointer to the stack taht points to the current state
	DynamicArray<State*> m_StateList;
	Stack<State*> m_CurrentState;
};

