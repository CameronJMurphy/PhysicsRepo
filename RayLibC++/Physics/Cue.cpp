#include "Cue.h"


Cue::Cue(Rigidbody* _ball) : ball(_ball)
{

}


void Cue::HitBall()
{
	//Get mouse pos
	Vector2 mPos = GetMousePosition(); 
	//convert raylib to glm
	glm::vec2 mousePos;
	mousePos.x = mPos.x;
	mousePos.y = mPos.y;

	//get direction vector
	glm::vec2 dirVec = ball->GetPosition() - mousePos;
	//See how far away it is for power
	float power = glm::length(dirVec) * 100.f;
	//normalize vec
	dirVec = glm::normalize(dirVec);


	//apply velocity to ball in direction
	ball->ApplyForce(dirVec * power);

}