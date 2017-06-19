#include "ObjectPool.h"
#include "Bullet.h"

ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	m_pPool = new Bullet*[nMaxSize];
	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new Bullet();
	}
}

ObjectPool::~ObjectPool()
{
	for(int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pPool[i];
	}
	delete[] m_pPool;
}

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

void ObjectPool::DeAllocate(Bullet* object)
{
	object->setActive(false);
}

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

void ObjectPool::update(float deltaTime)
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
			m_pPool[i]->update(deltaTime);
	}
}