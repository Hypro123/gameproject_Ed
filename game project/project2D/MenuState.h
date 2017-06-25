#pragma once
#include "State.h"
#include "Texture.h"

class MenuState : public State
{
public:
	//Constructor and deconstructor
	MenuState();
	~MenuState();

	//Calls this function when the state is first called
	void OnEnter();

	//Updates the function over time
	void OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer);

	//Draws the state's scene
	void OnDraw(aie::Renderer2D* m_2dRenderer);

	//Calls this function when this state is exiting
	void OnExit();

	//The Textrues used for the menu Screen
	aie::Texture* m_pMenuTexture;
	aie::Texture* m_pTitle;
	aie::Texture* m_pStartText1;
	aie::Texture* m_pStartText2;

	//keeps track of what number of seconds it is
	float spriteNo;
};

