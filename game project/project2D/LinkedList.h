#pragma once
#include "ListNode.h"

template
<typename T>
class LinkedList
{
public:
	LinkedList()
	{
		start = new ListNode<T>();
		end = new ListNode<T>();

		start->next = end;
		start->prev = nullptr;

		end->next = nullptr;
		end->prev = start;
	}

	~LinkedList()
	{
		delete start;
		delete end;
	}

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

	void pushBack(T value)
	{
		insert(value, end->prev, end);
	}

	void pushFront(T value)
	{
		insert(value, start, start->next);
	}

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

	int Size()
	{
		return Count;
	}

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

	void clear()
	{
		while(start->next != end)
		{
			popBack();
		}
	}

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