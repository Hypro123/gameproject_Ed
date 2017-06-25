#pragma once

#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix3.h"
#include "GameObject.h"

class Rock : public GameObject
{
public:
	//Rock's constructor adn deconstructor
	Rock();
	~Rock();

	//Draws the rock
	void drawRock(aie::Renderer2D* m_2dRenderer);

	//Rock's texture
	aie::Texture* m_rock;
	aie::Renderer2D* m_2dRenderer;
	
	//Rock's position
	Matrix3 rockPos;
};

