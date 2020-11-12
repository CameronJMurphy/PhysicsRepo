#pragma once
#include "Rigidbody.h"
#include <vector>
#include "PhysicsScene.h"
#include "Sphere.h"
#include "Plane.h"

class PoolTable
{
protected:
	std::vector<PhysicsObject*> walls;
	std::vector<Rigidbody*> holes;
	std::vector<Rigidbody*> balls;
	Rigidbody* whiteBall;
	glm::vec2 whitePos = glm::vec2{ 150,220 };
	PhysicsScene* const scene;
	float ballRadius = 10.f;
public:
	PoolTable(PhysicsScene* ps);
	void PositionBalls();
	Rigidbody* GetWhiteBall() { return whiteBall; }
	void HitHole(Rigidbody* object);
};

