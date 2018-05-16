#include "Player.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>
#include "Bullet.h"
#include <iostream>
#include <math.h>

Player::Player()
{
}

Player::Player(glm::vec2 * pos)
{	//texture
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_pos = pos;
	//amount of bullets
	for (int i = 0; i < 2500; ++i)
	{
		m_bullet = new Bullet();
		m_INactiveBullets.push_back(m_bullet);
	}

}
int errorHandle() {
	throw 1;
}

Player::~Player()
{
	delete m_texture;
	delete m_bullet;
}
//current player position
float Player::m_posx()
{
	return m_pos->x;
}
//current player position
float Player::m_posy()
{
	return m_pos->y;
}

void Player::Update(float deltaTime, aie::Input* input)
{	//calling lin
	int timer;
	timer = deltaTime +2;
	m_pos->x += timer;
	//m_pos->y = linearfunct(m_pos->x);
	//sin/cos/tan
	m_pos->y = tan(m_pos->x);

	//Player fire key SPACE key
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		//generating new bullets then pushing the active ones to inactive
		Bullet *newBullet;
		newBullet = m_INactiveBullets.at(m_INactiveBullets.size() - 1);
		newBullet->BulletPosX = m_pos->x;
		newBullet->BulletPosY = m_pos->y;
		m_activeBullets.push_back(newBullet);
		m_INactiveBullets.pop_back();
		//showing in iostream the active and inactive
		std::cout << "inactive: " << m_activeBullets.size() << std::endl;
		std::cout << "active: " << m_INactiveBullets.size() << std::endl;


	}
	//amount of bullets
	if (m_activeBullets.size() >= 2500)
	{
		for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
		{
			//current bullets and speed with the poisitioning of the bullet
			Bullet* usedBullet;
			if ((*it)->BulletPosY >= 720)
			{
				usedBullet = m_activeBullets.at(m_activeBullets.size() - 1);
				usedBullet->BulletPosX = m_pos->x;
				usedBullet->BulletPosY = m_pos->y;
				m_INactiveBullets.push_back(usedBullet);
				m_activeBullets.pop_back();
			}
		}
	}
	for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
	{
		(*it)->Update(deltaTime);
	}
	//Player movement D key with speed +borader
	if (input->isKeyDown(aie::INPUT_KEY_D) && m_pos->x <= 1250)
	{
		m_pos->x += 250.0f * deltaTime;
	}
	//Player movement A key with speed +borader
	if (input->isKeyDown(aie::INPUT_KEY_A) && m_pos->x >=25)
	{
		m_pos->x -= 250.0f * deltaTime;
	}	
	//Player movement W key with speed +borader
	if (input->isKeyDown(aie::INPUT_KEY_W) && m_pos ->y <=720)
	{
		m_pos->y += 250.0f * deltaTime;
	}
	//Player movement S key with speed +borader
	if (input->isKeyDown(aie::INPUT_KEY_S) && m_pos->y >= 25)
	{
		m_pos->y -= 100.0f * deltaTime;
	}

}
//rendering the players ship
void Player::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y);

	for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
	{
		(*it)->Draw(spriteBatch);
	}

}

float Player::linearfunct(float x)
{
	return x * 0.5f;
}



