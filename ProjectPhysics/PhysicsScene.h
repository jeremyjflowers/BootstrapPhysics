#pragma once
#include "glm/vec2.hpp"
#include <set>

class PhysicsObject;

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);

	void update(float deltaTime);
	void draw();

	void setGravity(const glm::vec2 gravity);
	glm::vec2 getGravity() const (return m_gravity;)

	void setTimeStep(const float timeStep);
	float getTimeStep() const;

private:
	glm::vec2 m_gravity;
	float m_timeStep;
	std::set<PhysicsObject*> m_actors;
};

