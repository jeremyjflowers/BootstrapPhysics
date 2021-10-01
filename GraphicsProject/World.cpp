#include "World.h"
#include "glm\ext.hpp"


World::World(int width, int height)
{
	m_width = width;
	m_height = height;
}

void World::start()
{
	//Initialize the quad
	m_quad.setTransform(glm::mat4(10.0f));
}

void World::update()
{
}

void World::draw()
{
	m_quad.draw();
}

void World::end()
{
}

glm::mat4 World::getProjectionViewModel()
{
	return m_projectionMatrix * m_viewMatrix * m_quad.getTransform();
}
