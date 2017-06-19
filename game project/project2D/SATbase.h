#pragma once
#include "GameObject.h"
#include "Hit.h"

class SATbase
{
public:
	static SATbase* GetInstance();
	static void Create();
	static void Destroy();

	void CreateObject(GameObject* pObject);
	void RemoveObject(GameObject* pObject);

	Hit CheckCollisions(GameObject* pObject);

private:
	SATbase();
	~SATbase();

	static SATbase* m_instance;

	DynamicArray<GameObject*> m_collisionList;
};

