#pragma once
#include "GameObject.h"
#include"Renderer2D.h"
#include"Texture.h"

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	//All of the textures the bullet will require
	aie::Texture* bulletTexture;
	aie::Texture* explosionTexture;
	aie::Renderer2D* m_2dRenderer;

	//Bullets update function is responsible for the bullets inetractions
	void update(float deltaTime);
	//Ths is responsible for drawing the bullet in the correct way, eg. if a bullet collides it should explode
	void draw(aie::Renderer2D* m_2dRenderer);

	//Bullets speed and direction
	float m_fspeed;
	Vector2 dir;

	//Checks whether the bullet should be drawn or update or whether it should interact with anything
	void setActive(bool bActive);
	//Checks whether it is active or not
	bool GetActive();

	//timer to see if it shoudl despawn
	float m_ftimer;
	//Collision timer
	float colTimer;

private:
	//Private Boolean
	bool m_bActive;
	
	//hold whether  the bullet has collided or not
	bool collided;

	//Collider
	float ColH;
	float ColW;
};

