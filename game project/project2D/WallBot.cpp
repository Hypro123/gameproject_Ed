#include "WallBot.h"
#include "SATbase.h"
#include "ResourceManager.h"

using namespace aie;

WallBot::WallBot()
{
	ResourceManager<aie::Texture>* m_pResourceMan = ResourceManager<Texture>::getInstance();

	TBTexture = m_pResourceMan->LoadResource("./textures/TB_WALL.png");

	//Collisions
	this->setTag(ROCK);
	TW = TBTexture->getWidth();
	TH = TBTexture->getHeight();
	setDimensions(TW, TH);
	local_Transform.setPosition(0, -2048);

	SATbase::GetInstance()->CreateObject(this);
	updateGlobalTransform();
}


WallBot::~WallBot()
{
	delete TBTexture;
}

void WallBot::draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(TBTexture, global_Transform);
}