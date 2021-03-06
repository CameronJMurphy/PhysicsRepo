#include "Rigidbody.h"

Rigidbody::Rigidbody(ShapeType shapeID, glm::vec2 pos, glm::vec2 vel, float rotation, float m)
	: PhysicsObject(shapeID)
	,position{pos}
	,velocity{vel}
	,mass{m}
{
	elasticity = 1;
	startPos = position;
}
Rigidbody::~Rigidbody()
{
	
}


void Rigidbody::FixedUpdate(const glm::vec2& gravity, float fixedTimeStep)
{
	//Gravity
	ApplyForce((gravity * mass) * fixedTimeStep);
	//slow velocity through drag
	velocity = velocity - (velocity * (linearDrag * fixedTimeStep));
	//angularVelocity -=  angularVelocity * angularDrag * fixedTimeStep;

	//if velocity gets super low, just make it equal 0
	if (glm::length(velocity) < 0.1f)
	{
		velocity = glm::vec2{0,0};
	}
	/*if (fabs(angularVelocity) < 0.01f)
	{
		angularVelocity = 0;
	}*/

	//applying velocity to position
	position = position + (velocity * fixedTimeStep);
}

void Rigidbody::ApplyForce(glm::vec2 force)
{
	if (mass != 0)
	{
		// apply force accounting for mass
		glm::vec2 acceleration = force / mass;
		velocity = velocity + acceleration;
	}
}
void Rigidbody::ApplyForceToActor(Rigidbody* actor2, glm::vec2 force)
{
	//both actors have forces applied in opposite directions
	actor2->ApplyForce(force);
	this->ApplyForce(force * -1.f);
}


void Rigidbody::ResolveCollision(Rigidbody* other)
{

	glm::vec2 normal = glm::normalize(other->GetPosition() - position);
	glm::vec2 relativeVel = other->GetVelocity() - velocity;
	//Elasticity
	float e = (elasticity + other->GetElasticity()) * 0.5f;
	float j = glm::dot(normal, -1.f *(relativeVel * ((1 + e) * -1))) / 
			glm::dot(normal, normal * ((1 / mass) + (1 / other->GetMass())));

	glm::vec2 force = normal * j;
	//push actors away
	ApplyForceToActor(other, force * -1.f);
}

void Rigidbody::SetPosition(glm::vec2 pos)
{
	position = pos;
}

void Rigidbody::ResetPosition()
{
	SetPosition(startPos);
}