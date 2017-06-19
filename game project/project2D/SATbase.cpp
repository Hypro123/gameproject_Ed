#include "SATbase.h"
#include "Vector2.h"
#include "DynamicArray.h"

SATbase* SATbase::m_instance = nullptr;

SATbase::SATbase()
{
}

SATbase::~SATbase()
{
}

SATbase* SATbase::GetInstance()
{
	return m_instance;
}

void SATbase::Create()
{
	if (m_instance == nullptr)
		m_instance = new SATbase();
}

void SATbase::Destroy()
{
	delete m_instance;
}

void SATbase::CreateObject(GameObject* pObject)
{
	m_collisionList.PushBack(pObject);
}

void SATbase::RemoveObject(GameObject* pObject)
{
	for(int i = 0; i < m_collisionList.Size() - 1; i++)
	{
		if(pObject == m_collisionList[i])
		{
			m_collisionList.Remove(i);
			break;
		}
	}
}

//check if colliding
Hit SATbase::CheckCollisions(GameObject* pObject)
{
	Hit hit;

	for (int i = 0; i < m_collisionList.Size(); ++i)
	{
		float minCol = 999999;
		bool bColliding = true;
		Vector2 V2norm;

		if (pObject == m_collisionList[i])
			continue;
		
		Collider Obj = pObject->GetCollider();

		//project all corners against all normals, dot product
		for (int j = 0; j < 4; j++)
		{
			float max1 = -9999999;
			float min1 = 9999999;

			for (int k = 0; k < 4; k++)
			{
				float temp = m_collisionList[i]->GetCollider().Corners[k].dot(Obj.normals[j]);
				
				if (temp > max1)
					max1 = temp;

				if (temp < min1)
					min1 = temp;
			}
		
			float max2 = -999999;
			float min2 = 999999;

			for (int k = 0; k < 4; k++)
			{
				float temp = Obj.Corners[k].dot(Obj.normals[j]);

				if (temp > max2)
					max2 = temp;

				if (temp < min2)
					min2 = temp;
			}

			if (max1 > min2 && max2 < min1)
			{
				/*hit.ety = nullptr;
				return hit;*/
				bColliding = false;
				break;
			}

			//finding min normal
			float St1 = max1 - min2;
			float St2 = max2 - min1;
			
			if (St1 < minCol)
			{
				minCol = St1;
				V2norm = Obj.normals[j];
			}

			if (St2 < minCol)
			{
				minCol = St2;
				V2norm = Obj.normals[j];
			}

		}

		if (!bColliding)
			continue;

		for (int j = 0; j < 4; j++)
		{
			float max1 = -9999999;
			float min1 = 9999999;

			for (int k = 0; k < 4; k++)
			{
				float temp = m_collisionList[i]->GetCollider().Corners[k].dot(m_collisionList[i]->GetCollider().normals[j]);

				if (temp > max1)
					max1 = temp;

				if (temp < min1)
					min1 = temp;
			}

			float max2 = -999999;
			float min2 = 999999;

			for (int k = 0; k < 4; k++)
			{
				float temp = Obj.Corners[k].dot(m_collisionList[i]->GetCollider().normals[j]);

				if (temp > max2)
					max2 = temp;

				if (temp < min2)
					min2 = temp;
			}

			if (max1 > min2 && max2 < min1)
			{
				/*hit.ety = nullptr;
				return hit;*/
				bColliding = false;
				break;
			}
			//finding min normal
			float St1 = max1 - min2;
			float St2 = max2 - min1;

			if (St1 < minCol)
			{
				minCol = St1;
				V2norm = m_collisionList[i]->GetCollider().normals[j];
			}

			if (St2 < minCol)
			{
				minCol = St2;
				V2norm = m_collisionList[i]->GetCollider().normals[j];
			}

		}
		if (!bColliding)
			continue;

		hit.ety = m_collisionList[i];
		hit.depth = minCol;
		hit.norm = V2norm;

		Vector2 dir = pObject->GetPosition() - m_collisionList[i]->GetPosition();
		dir.normalise();
		float res = dir.dot(hit.norm);
		if (res < 0)
			hit.norm = -hit.norm;

		return hit;
	}
	hit.ety = nullptr;
	return hit;
}