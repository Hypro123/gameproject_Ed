#pragma once
#include"Renderer2D.h"

class Bullet;

class ObjectPool
{
public:
	ObjectPool(int nMaxSize);
	~ObjectPool();

	Bullet* Allocate();
	void DeAllocate(Bullet* object);

	void update(float deltaTime);
	void draw(aie::Renderer2D* m_2dRenderer);

	Bullet** m_pPool;
	int m_nMaxSize;
};
