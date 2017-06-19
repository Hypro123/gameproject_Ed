#pragma once

#include"Renderer2D.h"
#include"Texture.h"
#include"Matrix3.h"
#include "GameObject.h"
#include "Collider.h"
#include"SATbase.h"
#include "ResourceManager.h"

class ObjectPool;

class Player : public GameObject
{
public:
	Player();
	~Player();
	

	void draw(aie::Renderer2D* m_2dRenderer);
	void update(float deltaTime);

	aie::Texture* m_shipTexture;
	aie::Renderer2D* m_2dRenderer;

protected:

	float rotSpeed;
	float speed;
	float mass;
	float drag;

	Vector2 Velocity;

	ObjectPool* objectpool;

private:
	//Collider
	float ColH;
	float ColW;
};

