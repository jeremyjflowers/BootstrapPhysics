#pragma once
#include "Quad.h"
#include "glm\mat4x4.hpp"

class World
{
public:
	World();
	World(int width, int height);
	~World() {}

	void start();
	void update();
	void draw();
	void end();

	glm::mat4 getProjectionViewModel();

private:
	int m_width = 1280;
	int m_height = 780;

	Quad m_quad = Quad(glm::vec4(0.2f, 0.8f, 0.6f, 1.0f));
	glm::mat4 m_viewMatrix = glm::mat4(1.0f);
	glm::mat4 m_projectionMatrix = glm::mat4(1.0f);
};

