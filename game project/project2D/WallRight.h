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

	void draw(aie::Renderer2D* m_2dRenderer);

	aie::Texture* LRTexture;

private:
	float RW;
	float RH;
};

