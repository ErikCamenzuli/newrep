#pragma once
namespace aie
{
	class Input;
	class Renderer2D;
}
class State
{
public:
	virtual void Update(float deltaTime, aie::Input* input) = 0;
	virtual void Draw(aie::Renderer2D* renderer);
};