#pragma once
#include"String.h"
#include <crtdbg.h>

template
<typename T>
class Resource
{
public:
	//-----------------------------------------
	//Initalises the resource with a file name 
	//-----------------------------------------
	Resource(char* szFileName)
	{
		int length = strlen(szFileName) + 1;
		m_szFileName = new char[length + 1];
		strcpy_s(m_szFileName, length, szFileName);
		
		m_Data = new T(szFileName);
		_ASSERT(m_Data);
	}
	//-------------------------------------------------
	//Deletes the resources after they have bbeen used
	//-------------------------------------------------
	~Resource()
	{
		delete m_Data;
		delete[] m_szFileName;
	}

	char* m_szFileName;
	T* m_Data;
};