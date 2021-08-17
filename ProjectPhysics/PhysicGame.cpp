#include "PhysicGame.h"
#include "Input.h"
#include "Font.h"
#include "Gizmos.h"

bool PhysicGame::startup()
{
	m_renderer = new aie::Renderer2D();
	setBackgroundColour(0.3f, 0.0f, 0.5f, 0.0f);
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	return true;
}

void PhysicGame::shutdown()
{
	delete m_renderer;
	delete m_font;
}

void PhysicGame::update(float deltaTime)
{
	//Get the input instance
	aie::Input* input = aie::Input::getInstance();

	//Exit on Esc
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
}

void PhysicGame::draw()
{
	clearScreen();

	m_renderer->begin();

	m_renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_renderer->drawText(m_font, fps, 0.0f, 0.0f);

	m_renderer->end();
}
