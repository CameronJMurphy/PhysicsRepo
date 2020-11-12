#pragma once
#include <glm/glm.hpp>
#include "Rigidbody.h"

class Cue
{
protected:
	Rigidbody* ball;
public:
	Cue(Rigidbody* _ball);
	void HitBall();
};

