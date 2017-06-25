#pragma once
#include "GameObject.h"
#include "Hit.h"

class SATbase
{
public:
	//gets an instance of the collider
	static SATbase* GetInstance();
	//SAT collision's acting constructor and deconstructor
	static void Create();
	static void Destroy();

	//Creates the Collider
	void CreateObject(GameObject* pObject);
	//Removes the collider object
	void RemoveObject(GameObject* pObject);
	//Returns the collision and does the checks
	Hit CheckCollisions(GameObject* pObject);

private:
	//SAT collisions constructor and deconstructor
	SATbase();
	~SATbase();

	static SATbase* m_instance;

	//Checks with all of the objects in the dynamic array
	DynamicArray<GameObject*> m_collisionList;
};

