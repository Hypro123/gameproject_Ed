#pragma once
#include "ListNode.h"
#include <crtdbg.h>

template
<typename T>
class LinkedList
{
public:
	
	//------------------------------------------------------------------------------------------
	//Initialises the Linked list and sets all of the pointers and data to what they need to be
	//------------------------------------------------------------------------------------------

	LinkedList()
	{
		start = new ListNode<T>();
		_ASSERT(start);
		end = new ListNode<T>();
		_ASSERT(end);
		start->next = end;
		start->prev = nullptr;

		end->next = nullptr;
		end->prev = start;
	}

	//-------------------------------------------------------------------------
	//Deconstructs the start and end pointers when they are no longer required
	//-------------------------------------------------------------------------

	~LinkedList()
	{
		delete start;
		delete end;
	}

	//------------------------------------------
	//Inserts a new listnode into a linked list
	//------------------------------------------

	void insert(T value, ListNode<T>* prev, ListNode<T>* next)
	{
		ListNode<T> NewNode = new ListNode<T>();
		
		NewNode->Data = value;
		
		NewNode->next = next;
		NewNode->prev = prev;
		
		prev->next = NewNode;
		next->prev = NewNode;
		NewNode->prev = prev;
	}

	//--------------------------------
	//Pushes the value down the stack
	//--------------------------------

	void pushBack(T value)
	{
		insert(value, end->prev, end);
	}

	//------------------------------------------
	//Pushes the data to the next list location
	//------------------------------------------

	void pushFront(T value)
	{
		insert(value, start, start->next);
	}

	//-------------------------------------------------------
	//Inserts a value into the particular specified location
	//eg. data -> list[3] if filled it wont work if it is not 
	//filled then add to the location.
	//-------------------------------------------------------

	void IndexInsert(T value, int index)
	{
		ListNode<T>* current = start;
		for(int i = 0; i < index; ++i)
		{
			if(current->next == end)
			{
				//Can't index, invalid location
				return;
			}
			current = current->next;
		}
		insert(value, current, current->next);
	}
	
	//-------------------------------------------
	//returns the first piece of data in the list
	//-------------------------------------------

	T First()
	{
		//List is empty
		if (start->next == end)
		{
			return default;
		}
		else
		{
			T value = start->next->Data;
			return value;
		}
	}

	//------------------------------------------
	//returns the last piece of data in the list
	//------------------------------------------

	T Last()
	{
		//List is emtpy
		if(start->next == end)
		{
			return default;
		}
		else
		{
			T value = end->prev->Data;
			return value;
		}
	}

	//------------------------------------
	//returns the size of the linked list
	//------------------------------------

	int Size()
	{
		return Count;
	}

	//----------------------------------------
	//Checks whether the list is empty or not
	//----------------------------------------

	bool empty()
	{
		if (start->next == end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//---------------------------------------------------
	//takes away the last data value in the list
	//---------------------------------------------------

	T popBack()
	{
		ListNode<T>* n = end = end->prev;
		T tempData = n->Data;
		if(n != start)
		{
			n->prev->next = end;
			end->prev = n->prev;
			delete n;
			--Count;
			return tempData;
		}
		else
		{
			return default;
		}
	}

	//----------------------------------------------------------
	//Takes away the first element in the list
	//----------------------------------------------------------

	T popFront()
	{
		ListNode<T>* n = start->next;
		T tempData = n->Data;
		if(n != end)
		{
			n->next->prev = start;
			start->next = n->next;
			delete n;
			--Count;
			return tempData;
		}
		else
		{
			return default;
		}
	}

	//------------------------------------------------------
	//Clears the entire list
	//------------------------------------------------------

	void clear()
	{
		while(start->next != end)
		{
			popBack();
		}
	}

	//------------------------------------------------------------
	//Erases a particular list value and clears the list location
	//------------------------------------------------------------

	void erase(int index)
	{
		ListNode<T>* current = start;
		for(int i = 0; i < index; ++i)
		{
			if(current->next == end)
			{
				return;
			}
			current = current->next;
		}
		if(current == start || current == end)
		{
			//Can't delete start and end
			return;
		}
		current->next->prev = current->prev;
		current->prev->next = current->next;
		delete current;
		--Count;
	}

	//--------------------------------------------------------------------
	//Removes a particular value and leaves the location blank/rand value
	//--------------------------------------------------------------------

	void remove(T value)
	{
		ListNode<T>* temp = nullptr;
		ListNode<T>* current = start->next;
		while(current->next != end)
		{
			if(current->next == end)
			{
				//Cant find index location
				return;
			}
			if(current->Data == value)
			{
				temp = current->prev;
				current->next->prev = current->prev;
				current->prev->next = current->next;
				delete current;
				current = temp;
				--Count;
			}
			current = current->next;
		}
	}

	ListNode<T>* start;
	ListNode<T>* end;
	int Count = 0;
};