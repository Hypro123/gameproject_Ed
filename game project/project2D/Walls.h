#pragma once

#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix3.h"
#include "GameObject.h"

//----------------------------------------------------------------------
//Althought this class is called "Walls" it is actually the top wall and
//was the first wall created although it was initially planned for this
//to be a common wall class.
//----------------------------------------------------------------------
class Walls : public GameObject
{
public:
	//Constructor and deconstructor
	Walls();
	~Walls();

	//Drawing of the walls
	void draw(aie::Renderer2D* m_2dRenderer);

	//exture of the wall pointer
	aie::Texture* TBTexture;

	//dimensions of the wall
private:
	float TW;
	float TH;
};

