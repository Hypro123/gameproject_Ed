#include "StateMachine.h"

//------------------------------------------------------------------
//Sets the background to not render by default, allows for changing 
//of one state to another without unloading another state
//------------------------------------------------------------------

StateMachine::StateMachine()
{
	m_bRenderBackground = false;
}

//----------------------------------
//Deconstructor
//----------------------------------

StateMachine::~StateMachine()
{
}

//-------------------------------------------------------------------------
//Updates the states in order as the next state is pushed onto the stack
//-------------------------------------------------------------------------

void StateMachine::Update(float fDeltaTime, aie::Renderer2D* m_2dRenderer)
{
	if (m_CurrentState.Size() <= 0)
		return;

	m_CurrentState.Top()->OnUpdate(fDeltaTime, this, m_2dRenderer);
}

//-------------------------------------------------------
//Draws all of the states as the next state is pushed on
//-------------------------------------------------------

void StateMachine::Draw(aie::Renderer2D* m_2dRenderer)
{
	if (m_CurrentState.Size() <= 0)
		return;

	if (m_bRenderBackground == true)
		m_CurrentState.SecondLast()->OnDraw(m_2dRenderer);

	m_CurrentState.Top()->OnDraw(m_2dRenderer);
}

//------------------------------------------------------
//Allows for the next state to be pushed onto the stack
//------------------------------------------------------

void StateMachine::pushState(int nStateIndex)
{
	if (m_CurrentState.Size() > 0)
		m_CurrentState.Top()->OnExit();

	m_CurrentState.Push(m_StateList[nStateIndex]);
	m_CurrentState.Top()->OnEnter();
}

//-----------------------------------------------------------------------
//Pops the State off the stack so that it will not need to be used later
//-----------------------------------------------------------------------

void StateMachine::popState()
{
	if (m_CurrentState.Size() > 0)
		m_CurrentState.Top()->OnEnter();

	m_CurrentState.Pop();
	if (m_CurrentState.Size() > 0)
		m_CurrentState.Top()->OnEnter();
}

//----------------------------------------------------------------------------
//Adds a state to the stack so that it can then later be called and pushed on
//----------------------------------------------------------------------------

void StateMachine::AddState(int nStateIndex, State * pState)
{
	m_StateList.Insert(nStateIndex, pState);
}

//-----------------------------------------------------
//Allows for the creation of a pause state for example
//-----------------------------------------------------

void StateMachine::setRenderBackGround(bool RenderBackground)
{
	m_bRenderBackground = RenderBackground;
}