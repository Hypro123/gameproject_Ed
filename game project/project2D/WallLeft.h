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

	void draw(aie::Renderer2D* m_2dRenderer);

	aie::Texture* LRTexture;

private:
	float LW;
	float LH;
};

