#pragma once
#include "State.h"
#include "Texture.h"

using namespace aie;

class PauseState : public State
{
public:
	PauseState();
	~PauseState();

	void OnEnter();
	void OnExit();

	void OnDraw(Renderer2D* m_2dRenderer);
	void OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);

	Texture* m_pPause;
};

