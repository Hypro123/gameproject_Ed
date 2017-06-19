#pragma once
#include "State.h"
#include "Texture.h"
#include "LoadingCircle.h"

class LoadingState : public State
{
public:
	LoadingState();
	~LoadingState();

	void OnEnter();

	void OnUpdate(float deltaTime, StateMachine* pObject);

	void OnDraw(aie::Renderer2D* m_2dRenderer);

	void OnExit();

	aie::Texture* m_ptexture;

	LoadingCircle* m_pCircle;

private:
	float timer;
};

