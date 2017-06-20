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

	void OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer);

	void OnDraw(aie::Renderer2D* m_2dRenderer);

	void OnExit();

	aie::Texture* m_ptexture;
	aie::Texture* m_phelp;

	LoadingCircle* m_pCircle;

private:
	float timer;
};

