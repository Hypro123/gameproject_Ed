#include "WallRight.h"
#include "SATbase.h"
#include "ResourceManager.h"

using namespace aie;

WallRight::WallRight()
{
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<Texture>::getInstance();

	LRTexture = m_pResourceMan->LoadResource("./textures/LR_WALL.png");

	//Collisions
	this->setTag(ROCK);
	RW = LRTexture->getWidth();
	RH = LRTexture->getHeight();
	setDimensions(RW, RH);
	local_Transform.setPosition(2048, 0);

	SATbase::GetInstance()->CreateObject(this);
	updateGlobalTransform();
}


WallRight::~WallRight()
{
	delete LRTexture;
}

void WallRight::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(LRTexture, global_Transform);
}
