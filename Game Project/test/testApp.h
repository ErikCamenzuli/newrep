#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"

class testApp : public aie::Application {
public:

	testApp();
	virtual ~testApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	Player* P1;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};