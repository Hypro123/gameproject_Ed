#pragma once

#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix3.h"
#include "GameObject.h"

class WallLeft : public GameObject
{
public:
	WallLeft();
	~WallLeft();

	//---------------------------------------------------------------------------
	//Drawing of the Left Wall on the map
	//---------------------------------------------------------------------------

	void draw(aie::Renderer2D* m_2dRenderer);

	//---------------------------------------------------------------------------
	//Texture of the Wall
	//Resources are managed to make sure it works effectivly
	//---------------------------------------------------------------------------

	aie::Texture* LRTexture;

	//---------------------------------------------------------------------------
	//These variables are used for storing the height and width of the Left wall
	//---------------------------------------------------------------------------

private:
	float LW;
	float LH;
};

