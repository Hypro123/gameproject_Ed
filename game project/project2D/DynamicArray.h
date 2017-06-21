#pragma once
#include<memory.h>
#include <crtdbg.h>

template <typename T>
class DynamicArray
{
public:
	
	//----------------------------------------------------
	//Initialisation of Dynamic array
	//
	//----------------------------------------------------

	DynamicArray(int initialSize = 0)
	{
		int nCapacity = initialSize;
		if (nCapacity <= 0)
			nCapacity = 1;

		m_pData = new T[nCapacity];
		_ASSERT(m_pData);
		m_nCapacity = nCapacity;
		m_nUsed = 0;
		m_nullvalue = 0;
		memset(&m_nullvalue, 0, sizeof(T));
	}


	//----------------------------------------------------
	//Deletes the Dynamic array to avoid memory leaks
	//
	//----------------------------------------------------

	~DynamicArray() 
	{
		delete m_pData;
	};


	//----------------------------------------------------
	//Another Constructor
	//
	//----------------------------------------------------

	DynamicArray(const DynamicArray& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;
		
		m_pData = new T[other.m_nCapacity];
		_ASSERT(m_pData);
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
		m_nullvalue = 0;
	}


	//----------------------------------------------------
	//PushBack function
	//
	//----------------------------------------------------

	void PushBack(T value)
	{
		if (m_nUsed >= m_nCapacity)
			reSize();

		m_pData[m_nUsed] = value;
		++m_nUsed;
	}


	//----------------------------------------------------
	//PushFront function
	//
	//----------------------------------------------------

	void PushFront(T value)
	{
		Insert(0, value);
	}


	//----------------------------------------------------
	//PopBack function
	//
	//----------------------------------------------------

	T PopBack()
	{
		--m_nUsed;
		return m_pData[m_nUsed];
	}


	//----------------------------------------------------
	//PopFront function
	//
	//----------------------------------------------------

	T PopFront()
	{
		return remove(0);
	}
	

	//----------------------------------------------------
	//deletes all values in the array
	//
	//----------------------------------------------------

	void clear()
	{
		m_nUsed = 0;
	}


	//----------------------------------------------------
	//Shrinks the Array maximum size to fit perfectly
	//
	//----------------------------------------------------

	void shrink()
	{
		int nCapacity = m_nUsed;
		if (nCapacity <= 0)
			nCapacity = 1;
		
		T* newData = new T[m_nUsed];
		_ASSERT(newData);
		memcpy(newData, m_pData, sizeof(T) * m_nUsed);
		
		delete m_pData;
		
		m_pData = newData;
		m_nCapacity = nCapacity;
	}


	//----------------------------------------------------
	//Allows for indexing
	//
	//----------------------------------------------------

	T& operator[](const int index)
	{
		return m_pData[index];
	}


	//----------------------------------------------------
	//inserting values into the Array
	//
	//----------------------------------------------------

	void Insert(int index, T value)
	{
		if (m_nUsed >= m_nCapacity)
			reSize();

		for (int i = m_nUsed - 1; i >= index; --i)
		{
			m_pData[i + 1] = m_pData[i];
		}
		m_pData[index] = value;
		++m_nUsed;
	}


	//----------------------------------------------------
	//Removes value from Array readjusts it afterwoods
	//
	//----------------------------------------------------

	T Remove(int index)
	{
		T value = m_pData[index];

		for (int i = index; index < m_nUsed; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		--m_nUsed;

		return value;
	}


	//----------------------------------------------------
	//returns the size of the Array
	//
	//----------------------------------------------------

	int Size()
	{
		return m_nUsed;
	}


	//----------------------------------------------------
	//returns the capacity of the Array
	//
	//----------------------------------------------------

	int Capacity()
	{	
		return m_nCapacity;
	}

	int m_nCapacity;
	int m_nUsed;
	T* m_pData;
	T m_nullvalue;

	DynamicArray& operator= (const DynamicArray& other) = default;
	DynamicArray(DynamicArray&& other) = default;
	DynamicArray& operator= (DynamicArray&& other) = default;

private:
	//----------------------------------------------------
	//The resize function only needs to be accessed by
	//functions in this template.
	//----------------------------------------------------
	
	void reSize()
	{
		//create new array with larger capacity
		T* newData = new T[m_nCapacity * 2];
		_ASSERT(newData);
		memcpy(newData, m_pData, sizeof(T) * m_nCapacity);

		//delete old array
		delete m_pData;

		//redefine where pointer points
		m_pData = newData;

		m_nCapacity = m_nCapacity * 2;
	}
};