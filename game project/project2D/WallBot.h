#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix3.h"
#include "GameObject.h"

class WallBot : public GameObject
{
public:
	WallBot();
	~WallBot();
	
	//---------------------------------------------------------------------------
	//Drawing of the Bottom Wall on the map
	//---------------------------------------------------------------------------
	
	void draw(aie::Renderer2D* m_2dRenderer);

	//---------------------------------------------------------------------------
	//Texture of the Wall
	//Resources are managed to make sure it works effectivly
	//---------------------------------------------------------------------------
	
	aie::Texture* TBTexture;
	
	//---------------------------------------------------------------------------
	//These variables are used for storing the height and width of the bottom wall
	//---------------------------------------------------------------------------

private:
	float TW;
	float TH;
};

