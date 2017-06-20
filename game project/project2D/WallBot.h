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

	void draw(aie::Renderer2D* m_2dRenderer);

	aie::Texture* TBTexture;

private:
	float TW;
	float TH;
};

