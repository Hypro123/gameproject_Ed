#pragma once
#include "DynamicArray.h"
#include "Resource.h"

template
<typename T>
class ResourceManager
{
public:
	//----------------------------------------------
	//Creates a new instance of the resourceManager
	//----------------------------------------------

	static void create()
	{
		m_Instance = new ResourceManager<T>();
	}
	
	//----------------------------------------------------
	//deletes the resources when they are no longer needed
	//----------------------------------------------------

	static void destroy()
	{
		m_Instance->UnloadAllResources();
		delete m_Instance;
	};

	//--------------------------------------------------------------------------------
	//Loads the Resources if they are not currently loaded, then returns the resource
	//--------------------------------------------------------------------------------

	T* LoadResource(char* szFileName)
	{
		//Check if resource is loaded
		for(int i = 0; i < m_ResourceList.Size(); ++i)
		{
			if(strcmp(m_ResourceList[i]->m_szFileName, szFileName) == 0)
			{
				return m_ResourceList[i]->m_Data;
			}
		}
		//Resource is not loaded so load it
		Resource<T>* pResource = new Resource<T>(szFileName);
		_ASSERT(pResource);
		m_ResourceList.PushBack(pResource);
		return pResource->m_Data;
	}

	//----------------------------------
	//Unloads all resources when called
	//----------------------------------

	void UnloadAllResources()
	{
		for(int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}

		m_ResourceList.clear();
	}

	//--------------------------------------------------------
	//Gets the instance of the resourceManager and returns it
	//--------------------------------------------------------

	static ResourceManager<T>* getInstance()
	{
		return m_Instance;
	}
	
	//-----------------------
	//The array of resources
	//-----------------------

	DynamicArray<Resource<T>*> m_ResourceList;

private:
	ResourceManager() {};
	~ResourceManager() {};
	static ResourceManager<T>* m_Instance;
};
//--------------------------------------------------------------------------
//initialises the resourceManager so that no issues occur when it is called
//--------------------------------------------------------------------------
template <typename T>
ResourceManager<T>* ResourceManager<T>::m_Instance = nullptr;