#pragma once
#include "DynamicArray.h"
#include "Resource.h"

template
<typename T>
class ResourceManager
{
public:
	static void create()
	{
		m_Instance = new ResourceManager<T>();
	}
	
	static void destroy()
	{
		m_Instance->UnloadAllResources();
		delete m_Instance;
	};

	T* LoadResource(char* szFileName)
	{
		//CHeck if resource is loaded
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

	void UnloadAllResources()
	{
		for(int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}

		m_ResourceList.clear();
	}

	static ResourceManager<T>* getInstance()
	{
		return m_Instance;
	}
	
	DynamicArray<Resource<T>*> m_ResourceList;

private:
	ResourceManager() {};
	~ResourceManager() {};
	static ResourceManager<T>* m_Instance;
};
template <typename T>
ResourceManager<T>* ResourceManager<T>::m_Instance = nullptr;