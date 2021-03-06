#include "Analytic.h"


Analytic::Analytic(glm::vec2 g, glm::vec2 initPos, glm::vec2 initVel, float b, float e, float ts) :
	gravity {g},
	initialPos {initPos},
	initialVel {initVel}

{
	//create arc from begining to end
	samples.reserve(20);
	for (; b < e; b += ts)
	{
		samples.push_back(Analyze(b));
	}
}

glm::vec2 Analytic::Analyze(float t)
{
	//return pos based on time
	float x = initialPos.x + initialVel.x * t;
	float y = initialPos.y + initialVel.y * t + gravity.y * 0.5f * t * t;
	return glm::vec2{ x,y };
}

void Analytic::Draw()
{
	//draw line between points in sample
	for (int i = 1; i < samples.size(); ++i)
	{
		auto beg = samples[i - 1];
		auto end = samples[i];
		DrawLine(beg.x, beg.y, end.x, end.y, Color{255,128,0,255});
	}
}
///Integrator
Intergrator::Intergrator(Rigidbody* _rb, glm::vec2 grav, float b, float e, float ts) :
	gravity{ grav },
	rb{ _rb },
	timeStep{ts}
{
	//create arc from begining to end
	samples.reserve(20);
	for (; b < e; b += timeStep)
	{
		samples.push_back(Analyze());
	}

}


glm::vec2 Intergrator::Analyze()
{
	//return position but update physics aswell
	glm::vec2 initPos = rb->GetPosition();
	rb->FixedUpdate(gravity,timeStep);
	return initPos;
}

void Intergrator::Draw()
{
	//draw line between points in sample
	for (int i = 1; i < samples.size(); ++i)
	{
		auto beg = samples[i - 1];
		auto end = samples[i];
		DrawLine(beg.x, beg.y, end.x, end.y, Color{ 255,128,0,255 });
	}
}