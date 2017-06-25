#pragma once
#include "State.h"
#include "Texture.h"

class SplashState : public State
{
public:
	//Constructor and Deconstructor
	SplashState();
	~SplashState();
	
	//Runs this code when entering the state
	void OnEnter();

	//Calls this when update is called for the state
	void OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer);

	//Runs this when the Draw function is called in each state
	void OnDraw(aie::Renderer2D* m_2dRenderer);

	//Runs this code when exiting the state
	void OnExit();
	
	//Initialises the textures for the splash screen for the writing
	aie::Texture* m_ptexture;
	aie::Texture* m_title;

private:
	float timer;
};

