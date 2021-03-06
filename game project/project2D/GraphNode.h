#pragma once
#include"LinkedList.h"

template
<typename T>
class GraphNode
{
public:
	GraphNode()
	{
		m_bTraversed = false;
	}

	GraphNode(T data)
	{
		m_Data = data;
		m_bTraversed = false;
	}

	//---------------------------------------
	//Adds connections in the graph
	//---------------------------------------

	void AddConnection(GraphNode<T>* other)
	{
		m_Edges->pushBack(other);
	}

	//------------------------------------------------
	//Removes connection between different graphnodes
	//------------------------------------------------

	void RemoveConnection(GraphNode<T>* other)
	{
		
		for(int i = 0; i < m_Edges->Size(); ++i)
		{
			if(m_Edges[i] == other)
			{
				m_Edges->remove(i);
				return;
			}
		}
	}

	LinkedList<T>* m_Edges;
	T m_Data;
	bool m_bTraversed;
};

