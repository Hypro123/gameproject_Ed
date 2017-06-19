#pragma once
#include "State.h"
#include "Texture.h"

class SplashState : public State
{
public:
	SplashState();
	~SplashState();
	
	void OnEnter();

	void OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer);

	void OnDraw(aie::Renderer2D* m_2dRenderer);

	void OnExit();
	
	aie::Texture* m_ptexture;
	aie::Texture* m_title;

private:
	float timer;
};

