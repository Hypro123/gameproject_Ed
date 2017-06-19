#include "Rock.h"
#include "Renderer2D.h"
#include "SATbase.h"

using namespace aie;

Rock::Rock()
{
	m_rock = new Texture("./textures/rock_large.png");

	this->setTag(ROCK);

	float rockWidth = m_rock->getWidth();
	float rockHeight = m_rock->getHeight();

	setDimensions(rockWidth, rockHeight);
	
	local_Transform.setPosition(300.0f, 300.0f);
	
	SATbase::GetInstance()->CreateObject(this);
	
	updateGlobalTransform();
}


Rock::~Rock()
{
	delete m_rock;
}

void Rock::drawRock(Renderer2D* m_2dRenderer)
{
	Matrix3 temp;
	//updateGlobalTransform();

	m_2dRenderer->drawSpriteTransformed3x3(m_rock, global_Transform);
}
