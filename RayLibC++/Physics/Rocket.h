#pragma once
#include "Rigidbody.h"
#include <raylib.h>
#include "PhysicsScene.h"

class Rocket : public Rigidbody
{
public:
	Rocket(PhysicsScene* ps, glm::vec2 pos, float t, float f);
	void FixedUpdate(const glm::vec2& gravity, float fdt) override;


	float thrust;
	float fuel;

	virtual void Draw() override;

private:
	PhysicsScene* const ps;
};

