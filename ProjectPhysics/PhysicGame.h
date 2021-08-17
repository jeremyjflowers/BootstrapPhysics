#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"

class PhysicGame : public aie::Application
{
public:
	PhysicGame() {}
	virtual ~PhysicGame() {}

	virtual bool startup();
	virtual void shutdown();
	virtual void update(float deltaTime);
	virtual void draw();

private:
	aie::Font* m_font;
	aie::Renderer2D* m_renderer;

	PhysicsScene* m_scene;
};

