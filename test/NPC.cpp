#include "NPC.h"
#include <Texture.h>
#include <Renderer2D.h>


NPC::NPC(glm::vec2 * pos)
{
	//movementX = 25;
	//movementY = 0;
	m_astriodTex = new aie::Texture("../bin/textures/rock_large.png");
	m_pos = pos;

	for (int i = 0; i < 1; ++i)
	{
	

	}

}

int errorhandle()
{
	throw 1;
}

NPC::~NPC()
{
	delete m_astriodTex;
}

float NPC::movementX()
{
	return m_pos->x;
}

float NPC::movementY()
{
	return m_pos->y;
}

void NPC::Update(float deltaTime)
{
	//movementX += 250.0f * deltaTime;

	NPC *newAstriod;
//	newAstriod->movementX = m_pos->x;
//  newAstriod->movementY = m_pos->y;



}

void NPC::Draw(aie::Renderer2D * m_2drenderer)
{
	//m_2drenderer->drawSprite(m_astriodTex, movementX, movementY);



}
