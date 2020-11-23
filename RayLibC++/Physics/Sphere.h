#pragma once
#include "Rigidbody.h"
#include <raylib.h>
#include <glm/glm.hpp>

class Sphere : public Rigidbody
{
public:
	Sphere(glm::vec2 position, glm::vec2 velocity, float mass, float radius, Color color);
	~Sphere();

	float GetRadius() const { return radius; }
	Color GetColour() const { return colour; }

	virtual void Draw() override;


protected:
	float radius;
	Color colour;
};

