#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include"Collider.h"
#include "DynamicArray.h"
#include "Tag.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	GameObject* m_parent;
	DynamicArray<GameObject*> m_children;

	Matrix3 global_Transform;
	Matrix3 local_Transform;

	Collider m_collider;
	Collider GetCollider();
	//Collider GetColliderC();

	Vector2 GetPosition();

	void updateGlobalTransform();
	void setParent(GameObject* sParent);
	void setChild(GameObject* sChild);

	Tag getTag();
	void setTag(Tag tag);

	void setDimensions(float W, float H);
	//void setDimensionsC(Vector2 pos, float rad);

//STATISTICS
	int m_fhealth;

private:
	Tag m_etag;

};


