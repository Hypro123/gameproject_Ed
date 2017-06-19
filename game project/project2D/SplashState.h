#pragma once
#include "State.h"
#include "Texture.h"
#include "StateMachine.h"

class SplashState : public State
{
public:
	SplashState();
	~SplashState();
	
	void OnEnter();

	void OnUpdate(float deltaTime, StateMachine* pObject);

	void OnDraw(aie::Renderer2D* m_2dRenderer);

	void OnExit();
	
	aie::Texture* m_ptexture;

private:
	float timer;
};

