#include "Bullet.h"
#include <Texture.h>
#include <Renderer2D.h>



Bullet::Bullet()
{
	BulletPosX = 0.0f;
	BulletPosY = 0.0f;
	m_bulletTex = new aie::Texture("../bin/textures/bullet.png");
}


Bullet::~Bullet()
{
	delete m_bulletTex;
}

void Bullet::Update(float deltaTime)
{
	BulletPosY += 500.0f * deltaTime;
}

void Bullet::Draw(aie::Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_bulletTex, BulletPosX, BulletPosY);
}

