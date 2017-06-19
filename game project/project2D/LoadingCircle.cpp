#include "LoadingCircle.h"
#include "ResourceManager.h"


LoadingCircle::LoadingCircle()
{
	local_Transform.setPosition(560, -300);
	ResourceManager<aie::Texture>* temp = ResourceManager<aie::Texture>::getInstance();
	m_loadCircle = temp->LoadResource("./textures/Loading.png");
	timer = 0;
}


LoadingCircle::~LoadingCircle()
{
}

void LoadingCircle::Update(float deltaTime)
{
	timer += deltaTime;
}

void LoadingCircle::Draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_loadCircle, 560, -300, 0.0f, 0.0f, timer * 5);
}