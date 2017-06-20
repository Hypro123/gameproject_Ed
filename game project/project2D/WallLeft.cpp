#include "WallLeft.h"
#include "SATbase.h"
#include "ResourceManager.h"

using namespace aie;

WallLeft::WallLeft()
{
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<Texture>::getInstance();

	LRTexture = m_pResourceMan->LoadResource("./textures/LR_WALL.png");

	//Collisions
	this->setTag(ROCK);
	LW = LRTexture->getWidth();
	LH = LRTexture->getHeight();
	setDimensions(LW, LH);
	local_Transform.setPosition(-2048, 0);

	SATbase::GetInstance()->CreateObject(this);
	updateGlobalTransform();
}


WallLeft::~WallLeft()
{
	delete LRTexture;
}

void WallLeft::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(LRTexture, global_Transform);
}
