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
	//initialises the player
	Player();
	//Player deconstructor
	~Player();
	
	//Draws the player
	void draw(aie::Renderer2D* m_2dRenderer);
	//Activates the players functions every frame
	void update(float deltaTime);

	//Player's texture
	aie::Texture* m_shipTexture;
	aie::Renderer2D* m_2dRenderer;

protected:
	//Players numbers for movement purposes
	float rotSpeed;
	float speed;
	float mass;
	float drag;

	//Velocity of the player
	Vector2 Velocity;

	//The objectpool of bullets is accessed from here
	ObjectPool* objectpool;

private:
	//Collider
	float ColH;
	float ColW;
};

