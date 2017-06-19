#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Player.h"
#include "Rock.h"
#include "SATbase.h"
#include "StateMachine.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	StateMachine* pStateMachine;

	Rock* rock;
	Player* player;

	SATbase* SAT;

protected:

	aie::Renderer2D*	m_2dRenderer;

	float m_cameraX, m_cameraY;
	float m_timer;
};