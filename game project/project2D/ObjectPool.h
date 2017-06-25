#pragma once
#include"Renderer2D.h"

class Bullet;

class ObjectPool
{
public:
	//Constructors of the object pool
	ObjectPool(int nMaxSize);
	~ObjectPool();

	//Allocating and deallocating space for the bullet objects
	Bullet* Allocate();
	void DeAllocate(Bullet* object);

	//Update adn draw functions
	void update(float deltaTime);
	void draw(aie::Renderer2D* m_2dRenderer);

	//pointer to the Bullet class pointers as well as a maximum size for the bullet object pool
	Bullet** m_pPool;
	int m_nMaxSize;
};
