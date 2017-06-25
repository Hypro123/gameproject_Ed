#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "Renderer2D.h"

//------------------------------------------------
//This object is just made for the laoding screen
//------------------------------------------------
class LoadingCircle : public GameObject
{
public:
	LoadingCircle();
	~LoadingCircle();

	//updates it spining
	void Update(float deltaTime);
	//Draws the spinning circle
	void Draw(aie::Renderer2D* m_2dRenderer);

	//loads the textrue of the circle
	aie::Texture* m_loadCircle;
	//Checks how long it should be spinning for 
	float timer;
};

