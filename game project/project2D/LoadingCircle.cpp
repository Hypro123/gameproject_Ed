#include "LoadingCircle.h"
#include "ResourceManager.h"


LoadingCircle::LoadingCircle()
{
	ResourceManager<aie::Texture>* temp = ResourceManager<aie::Texture>::getInstance();
	m_loadCircle = temp->LoadResource("./textures/barrelBeige.png");
	local_Transform.setPosition(560, -300);
}


LoadingCircle::~LoadingCircle()
{
}

void LoadingCircle::Update(float deltaTime)
{
	float rot = 0;
	rot -= 100 * deltaTime;
	Matrix3 temp;
	temp.setRotateZ(rot);
	local_Transform = local_Transform * temp;

	updateGlobalTransform();
}

void LoadingCircle::Draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_loadCircle, global_Transform, 0.0f, 0.0f, -0.1);
}