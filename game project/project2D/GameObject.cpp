#include "GameObject.h"
#include "VectorCast.h"



//------------
//Constructor
//------------
GameObject::GameObject()
{
	//Initialising Main components	
	m_parent = nullptr;
	setDimensions(100.0f, 100.0f);
}

//--------------
//Deconstructor
//--------------
GameObject::~GameObject()
{
}

//---------------------------------------------------
//Get position function is made here for convenience
//---------------------------------------------------
Vector2 GameObject::GetPosition()
{
	Vector2 pos;
	pos.x = global_Transform.m[2][0];
	pos.y = global_Transform.m[2][1];
	return pos;
}

//--------------------------------------------------------------------
//This function is used  to make an object a parent of anotehr object
//--------------------------------------------------------------------
void GameObject::setParent(GameObject* sParent)
{
	m_parent = sParent;
}

//--------------------------------------------------------------------
//This function is used in order to amke an object a child of another
//--------------------------------------------------------------------
void GameObject::setChild(GameObject* sChild)
{
	m_children.PushBack(sChild);
}

//--------------------------------------------------------------------
//This globaly updates the transform of all of the exising Gameobjects
//--------------------------------------------------------------------
void GameObject::updateGlobalTransform()
{
	if(m_parent != nullptr)
	{
		global_Transform = m_parent->global_Transform * local_Transform;
	}
	else
	{
		global_Transform = local_Transform;
	}
	for(int i = 0; i < m_children.Size(); i++)
	{
		m_children[i]->updateGlobalTransform();
	}
}

void GameObject::setTag(Tag tag)
{
	m_etag = tag;
}

Tag GameObject::getTag()
{
	return m_etag;
}

void GameObject::setDimensions(float W, float H)
{
	Vector2 Cpnt = global_Transform.getPosition();
	
	Vector2 BL((Cpnt.x - (W/2)), (Cpnt.y - (H/2)));
	Vector2 TR((Cpnt.x + (W/2)), (Cpnt.y + (H/2)));
	
	//Vector3 dir = global_Transform[0];

	//BotLeft
	m_collider.Corners[0].x = BL.x;
	m_collider.Corners[0].y = BL.y;

	//TopLeft
	m_collider.Corners[1].x = BL.x;
	m_collider.Corners[1].y = TR.y;

	//BotRight
	m_collider.Corners[2].x = TR.x;
	m_collider.Corners[2].y = BL.y;

	//TopRight
	m_collider.Corners[3].x = TR.x;
	m_collider.Corners[3].y = TR.y;

	Vector2 temp;
	//Left Normal
	temp = m_collider.Corners[1] - m_collider.Corners[0];
	m_collider.normals[0].x = temp.y;
	m_collider.normals[0].y = -temp.x;
	m_collider.normals[0].normalise();

	//Top Normal
	temp = m_collider.Corners[3] - m_collider.Corners[1];
	m_collider.normals[1].x = temp.y;
	m_collider.normals[1].y = -temp.x;
	m_collider.normals[1].normalise();

	//Right Normal
	temp = m_collider.Corners[0] - m_collider.Corners[2];
	m_collider.normals[2].x = temp.y;
	m_collider.normals[2].y = -temp.x;
	m_collider.normals[2].normalise();

	//Bot Normal
	temp = m_collider.Corners[2] - m_collider.Corners[3];
	m_collider.normals[3].x = temp.y;
	m_collider.normals[3].y = -temp.x;
	m_collider.normals[3].normalise();
}

//void GameObject::setDimensionsC(Vector2 pos, float rad)
//{
//	m_collider.CenterPoint = pos;
//	m_collider.Radius = rad;
//}

Collider GameObject::GetCollider()
{
	Collider col = m_collider;
	
	col.Corners[0] = CastTo<Vector2>(global_Transform * CastTo<Vector3>(col.Corners[0])) + GetPosition();
	col.Corners[1] = CastTo<Vector2>(global_Transform * CastTo<Vector3>(col.Corners[1])) + GetPosition();
	col.Corners[2] = CastTo<Vector2>(global_Transform * CastTo<Vector3>(col.Corners[2])) + GetPosition();
	col.Corners[3] = CastTo<Vector2>(global_Transform * CastTo<Vector3>(col.Corners[3])) + GetPosition();
	
	return col;
}

//Collider GameObject::GetColliderC()
//{
//	Collider col = m_collider;
//
//	col.Radius = m_collider.Radius;
//	col.CenterPoint = global_Transform.getPosition();
//
//	return col;
//}
