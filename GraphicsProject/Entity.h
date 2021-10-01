#pragma once
#include "Mesh.h";

class Entity
{
public:
	Entity();
	~Entity();

	void AddEntity();
	void DeleteEntity();

	void start();
	void update();
	void draw();
	void end();

private:
	Entity* m_entity;
	Entity* m_entities;

};

