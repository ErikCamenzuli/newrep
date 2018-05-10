#pragma once
#include <glm\vec2.hpp>
#include <vector>

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
}
class Bullet;
class Player
{
public:
	Player();
	Player(glm::vec2* pos);
	~Player();

	// get x
	float m_posx();
	// get y
	float m_posy();


	void Update(float deltaTime, aie::Input* input);
	void Draw(aie::Renderer2D* spriteBatch);


private:
	glm::vec2* m_pos;
	aie::Texture* m_texture;
	std::vector<Bullet*>m_activeBullets;
	std::vector<Bullet*>m_INactiveBullets;
	Bullet* m_bullet;
};

