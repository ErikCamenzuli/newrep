#pragma once
#include <glm\vec2.hpp>
#include <vector>

namespace aie
{
	class Renderer2D;
	class Texture;
}


class NPC
{
public:

	NPC(glm::vec2* pos);
	~NPC();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D * m_2drenderer);

	float movementX();
	float movementY();

private:

	glm::vec2* m_pos;
	aie::Texture* m_astriodTex;

};

