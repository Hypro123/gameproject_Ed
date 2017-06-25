#pragma once
#include "State.h"
#include "Texture.h"
#include "LoadingCircle.h"

class LoadingState : public State
{
public:
	//Constructor adn deconstructor
	LoadingState();
	~LoadingState();

	//Calls this function when the state is accessed
	void OnEnter();

	//Calls this function eery fram this State is active
	void OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer);

	//Draws the state while it is active
	void OnDraw(aie::Renderer2D* m_2dRenderer);

	//Calls this when it exits the state to another one
	void OnExit();

	//Textures for this state
	aie::Texture* m_ptexture;
	aie::Texture* m_phelp;

	//The loading circle object
	LoadingCircle* m_pCircle;

private:
	float timer;
};

