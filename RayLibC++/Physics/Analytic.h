#pragma once
#include <raylib.h>
#include <glm/glm.hpp>
#include <vector>
#include "Rigidbody.h"

class Analytic
{
private:
	glm::vec2 gravity;
	glm::vec2 initialPos;
	glm::vec2 initialVel;
	std::vector<glm::vec2> samples;
public:
	Analytic(glm::vec2 g, glm::vec2 initPos, glm::vec2 initVel, float b, float e, float ts = 0.1f);
	
	glm::vec2 Analyze(float t);

	void Draw();
};

class Intergrator
{
public:
	glm::vec2 gravity;
	std::vector<glm::vec2> samples;
	Rigidbody* rb;
	float timeStep;

	Intergrator(Rigidbody* _rb, glm::vec2 grav, float b, float e, float  ts);
	glm::vec2 Analyze();
	void Draw();
};

