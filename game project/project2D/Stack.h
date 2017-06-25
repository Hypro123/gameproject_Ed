#pragma once
#include "DynamicArray.h"

template <typename T>
class Stack
{
public:
	//---------------------------
	//Initialises the Stack
	//---------------------------
	Stack(int initialSize = 0)
	{
	}
	
	//----------------------------
	//Stack Deconstructor
	//----------------------------
	~Stack()
	{
	}

	//-----------------------------
	//Checks is the Stack is empty
	//-----------------------------
	bool IsEmpty()
	{
		return (m_pData.Size() == 0);
	}

	//-----------------------------------
	//Returns the Size of the Stack Data
	//-----------------------------------
	int Size()
	{
		return m_pData.Size();
	}

	//-------------------------------------------------------------------
	//Pushes the Data down the Stack, what comes in first comes out last
	//-------------------------------------------------------------------
	void Push(T value)
	{
		m_pData.PushBack(value);
	}

	//-------------------------------------------------
	//Pops the last peice of data that is on the stack
	//-------------------------------------------------
	T Pop()
	{
		return m_pData.PopBack();
	}

	//---------------------------------------------
	//Returns what data is at the top of the Stack
	//---------------------------------------------
	T Top()
	{
		int nTop = m_pData.Size() - 1;
		return m_pData[nTop];
	}


	//----------------------------------------------------------------------
	//Returns the data that is just bellow the data at the top of the stack
	//----------------------------------------------------------------------
	T SecondLast()
	{
		int nTop = m_pData.Size() - 2;
		return m_pData[nTop];
	}

	//------------------
	//The Array of Data
	//------------------
	DynamicArray<T> m_pData;
};

