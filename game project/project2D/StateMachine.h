#pragma once
#include "DynamicArray.h"
#include "State.h"
#include "Stack.h"



class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float fDeltaTime, aie::Renderer2D* m_2dRenderer);
	void AddState(int nStateIndex, State* pState);
	void Draw(aie::Renderer2D* m_2dRenderer);
	void pushState(int nStateIndex);
	void popState();

	void setRenderBackGround(bool RenderBackground);
private:
	bool m_bRenderBackground;
	
	DynamicArray<State*> m_StateList;
	Stack<State*> m_CurrentState;
};

