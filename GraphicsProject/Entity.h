#pragma once
#include "Mesh.h";

class Entity
{
public:
	Entity();
	Entity(int entities);
	~Entity();

	void start();
	void update();
	void draw();
	void end();

private:
	int m_entities;
	glm::mat4 entitiesArray = 
};

