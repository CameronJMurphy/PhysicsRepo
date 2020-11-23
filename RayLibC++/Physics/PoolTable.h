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
	Texture2D texture = LoadTexture("images/PoolTable.png");
public:
	PoolTable(PhysicsScene* ps);
	~PoolTable();
	void PositionBalls();
	Rigidbody* GetWhiteBall() { return whiteBall; }
	Texture2D GetTexture() { return texture; }
};

