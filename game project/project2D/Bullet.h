#pragma once
#include "GameObject.h"
#include"Renderer2D.h"
#include"Texture.h"

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	aie::Texture* bulletTexture;
	aie::Texture* explosionTexture;
	aie::Renderer2D* m_2dRenderer;

	void update(float deltaTime);
	void draw(aie::Renderer2D* m_2dRenderer);

	float m_fspeed;
	Vector2 dir;

	void setActive(bool bActive);
	bool GetActive();

	float m_ftimer;
	float colTimer;

private:
	bool m_bActive;
	
	bool collided;

	//Collider
	float ColH;
	float ColW;
};

