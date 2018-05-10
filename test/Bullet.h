#pragma once
namespace aie {
	class Renderer2D;
	class Texture;
}

class Bullet
{
public:
	Bullet();
	~Bullet();

	//draw funct
	void Update(float deltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);
	//x pos
	float BulletPosX;
	//y pos
	float BulletPosY;

private:
	//texture for bullet
	aie::Texture* m_bulletTex;
};

