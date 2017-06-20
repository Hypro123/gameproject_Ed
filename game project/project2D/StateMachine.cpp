#include "StateMachine.h"



StateMachine::StateMachine()
{
	m_bRenderBackground = false;
}


StateMachine::~StateMachine()
{
}

void StateMachine::Update(float fDeltaTime, aie::Renderer2D* m_2dRenderer)
{
	if (m_CurrentState.Size() <= 0)
		return;

	m_CurrentState.Top()->OnUpdate(fDeltaTime, this, m_2dRenderer);
}

void StateMachine::Draw(aie::Renderer2D* m_2dRenderer)
{
	if (m_CurrentState.Size() <= 0)
		return;

	if (m_bRenderBackground == true)
		m_CurrentState.SecondLast()->OnDraw(m_2dRenderer);

	m_CurrentState.Top()->OnDraw(m_2dRenderer);
}

void StateMachine::pushState(int nStateIndex)
{
	if (m_CurrentState.Size() > 0)
		m_CurrentState.Top()->OnExit();

	m_CurrentState.Push(m_StateList[nStateIndex]);
	m_CurrentState.Top()->OnEnter();
}

void StateMachine::popState()
{
	if (m_CurrentState.Size() > 0)
		m_CurrentState.Top()->OnEnter();

	m_CurrentState.Pop();
	if (m_CurrentState.Size() > 0)
		m_CurrentState.Top()->OnEnter();
}

void StateMachine::AddState(int nStateIndex, State * pState)
{
	m_StateList.Insert(nStateIndex, pState);
}

void StateMachine::setRenderBackGround(bool RenderBackground)
{
	m_bRenderBackground = RenderBackground;
}