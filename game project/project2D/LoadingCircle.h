#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "Renderer2D.h"

class LoadingCircle : public GameObject
{
public:
	LoadingCircle();
	~LoadingCircle();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);

	aie::Texture* m_loadCircle;
};

