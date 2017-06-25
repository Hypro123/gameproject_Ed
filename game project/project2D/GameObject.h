#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include"Collider.h"
#include "DynamicArray.h"
#include "Tag.h"

//------------------------------------
//This is the Entity class effectivly
//------------------------------------

class GameObject
{
public:
	GameObject();
	~GameObject();

	//Dynamic arrays are used here to take away the use of the STL vectors
	GameObject* m_parent;
	DynamicArray<GameObject*> m_children;

	//global and local transform of each particular game object
	Matrix3 global_Transform;
	Matrix3 local_Transform;

	//Does collidion checking and can get the collider from another object
	Collider m_collider;
	Collider GetCollider();

	//Gets the position of an object
	Vector2 GetPosition();

	//This updates the location of a gameobject in a global scale
	void updateGlobalTransform();
	//Can be used to make a gameobject a parent of another
	void setParent(GameObject* sParent);
	//Can be made so that one gameobject cna be a child of another gameobject
	void setChild(GameObject* sChild);

	//Gets the tag of the gameobject
	Tag getTag();
	//Sets the tag of a gameobject
	void setTag(Tag tag);

	//Sets the dimensions of the object's collider
	void setDimensions(float W, float H);

//This was going to be used for testing purposes
//STATISTICS
	//int m_fhealth;

private:
	//Checks the tag
	Tag m_etag;

};


