#include "ObjectPool.h"
#include "Bullet.h"
#include <crtdbg.h>

//-----------------------------------
//Initialisation of the Object Pool
//has to have a max size
//-----------------------------------
ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	m_pPool = new Bullet*[nMaxSize];
	_ASSERT(m_pPool);
	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new Bullet();
		_ASSERT(m_pPool[i]);
	}
}

//------------------------------------------
//Clears out the object pool when the
//object pool is unloaded
//------------------------------------------

ObjectPool::~ObjectPool()
{
	for(int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pPool[i];
	}
	delete[] m_pPool;
}

//--------------------------------------------
//Allocates the correct amount of space so 
//that the pool doesn't over use the memory
//--------------------------------------------

Bullet* ObjectPool::Allocate()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if(!m_pPool[i]->GetActive())
		{
			m_pPool[i]->setActive(true);
			return m_pPool[i];
		}
	}
	return nullptr;
}

//-------------------------------------------
//Deactivates the object pool
//-------------------------------------------

void ObjectPool::DeAllocate(Bullet* object)
{
	object->setActive(false);
}
//--------------------------------------------------------------------
//Allows for drawing multiple objects within the object pool
//--------------------------------------------------------------------

void ObjectPool::draw(aie::Renderer2D* m_2dRenderer)
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->draw(m_2dRenderer);
		}
	}
}

//--------------------------------------------------------
//Allows for updating all objects within the object pool
//-------------------------------------------------------

void ObjectPool::update(float deltaTime)
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
			m_pPool[i]->update(deltaTime);
	}
}