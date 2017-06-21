#pragma once

#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix3.h"
#include "GameObject.h"

class WallRight : public GameObject
{
public:
	WallRight();
	~WallRight();

	//---------------------------------------------------------------------------
	//Drawing of the Right Wall on the map
	//---------------------------------------------------------------------------

	void draw(aie::Renderer2D* m_2dRenderer);

	//---------------------------------------------------------------------------
	//Texture of the Wall
	//Resources are managed to make sure it works effectivly
	//---------------------------------------------------------------------------

	aie::Texture* LRTexture;

	//---------------------------------------------------------------------------
	//These variables are used for storing the height and width of the Right wall
	//---------------------------------------------------------------------------

private:
	float RW;
	float RH;
};

