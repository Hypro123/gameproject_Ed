#pragma once
#include "State.h"
#include "Texture.h"

class MenuState : public State
{
public:
	MenuState();
	~MenuState();

	void OnEnter();

	void OnUpdate(float deltaTime, StateMachine* pObject, aie::Renderer2D* m_2dRenderer);

	void OnDraw(aie::Renderer2D* m_2dRenderer);

	void OnExit();

	aie::Texture* m_pMenuTexture;
	aie::Texture* m_pTitle;
	aie::Texture* m_pStartText1;
	aie::Texture* m_pStartText2;

	float spriteNo;
};

