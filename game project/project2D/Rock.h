#pragma once

#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix3.h"
#include "GameObject.h"

class Rock : public GameObject
{
public:
	Rock();
	~Rock();

	void drawRock(aie::Renderer2D* m_2dRenderer);

	aie::Texture* m_rock;
	aie::Renderer2D* m_2dRenderer;

	Matrix3 rockPos;
};

