#include "testApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include <imgui.h>
#include "Bullet.h"


testApp::testApp() {

}

testApp::~testApp() {

}

bool testApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 0);
	P1 = new Player(new glm::vec2(100.0f, 200.0f));
	return true;
}

void testApp::shutdown() {
	delete P1;
	delete m_font;
	delete m_2dRenderer;
}

void testApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	P1->Update(deltaTime, input);
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void testApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//GUI interface showing player position
	ImGui::Begin("Player GUI");
	ImGui::Text("Player Position X: (%1.0F)", P1->m_posx());
	ImGui::Text("Player Position Y: (%1.0F)", P1->m_posy());
	ImGui::Text("Press Esc To Quit");
	ImGui::End();

	// draw your stuff here!

	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	P1->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}