#include "Rigidbody.h"
#include <raymath.h>

Rigidbody::Rigidbody(ShapeType shapeID, glm::vec2 pos, glm::vec2 vel, float rotation, float m)
	: PhysicsObject(shapeID)
	,position{pos}
	,velocity{vel}
	,mass{m}
{
	elasticity = 1;
}
Rigidbody::~Rigidbody()
{
	
}


void Rigidbody::FixedUpdate(const glm::vec2& gravity, float fixedTimeStep)
{
	//Gravity

	ApplyForce((gravity * mass) * fixedTimeStep);

	velocity = velocity - (velocity * (linearDrag * fixedTimeStep));
	angularVelocity -= angularVelocity * angularDrag * fixedTimeStep;


	if (glm::length(velocity) < 0.1f)
	{
		velocity = glm::vec2{0,0};
	}
	if (fabs(angularVelocity) < 0.01f)
	{
		angularVelocity = 0;
	}
	//applying velocity to position
	//position = Vector2Add(position, Vector2Scale(velocity, fixedTimeStep));
	position = position + (velocity * fixedTimeStep);
}

void Rigidbody::ApplyForce(glm::vec2 force)
{
	if (mass != 0)
	{
		glm::vec2 acceleration = force / mass;
		velocity = velocity + acceleration;
	}
}
void Rigidbody::ApplyForceToActor(Rigidbody* actor2, glm::vec2 force)
{
	actor2->ApplyForce(force);
	//this->ApplyForce(Vector2Negate(force));
	this->ApplyForce(force * -1.f);
}


void Rigidbody::ResolveCollision(Rigidbody* other)
{
	//Vector2 normal = Vector2Normalize(Vector2Subtract(other->GetPosition() , position));
	//Vector2  relativeVel = Vector2Subtract(other->GetVelocity(), velocity);
	////Elasticity
	//float e = (elasticity + other->GetElasticity()) * 0.5f;
	//float j = Vector2DotProduct(Vector2Scale( Vector2Scale(relativeVel, (1+e)*-1, normal), -1)
	//		/ Vector2DotProduct(normal, Vector2Scale(normal, ((1 / mass) + (1 / other->GetMass()))));

	//Vector2 force = Vector2Scale(normal, j);

	glm::vec2 normal = glm::normalize((other->GetPosition() - position));
	glm::vec2 relativeVel = other->GetVelocity() - velocity;
	//Elasticity
	float e = (elasticity + other->GetElasticity()) * 0.5f;
	float j = glm::dot(normal, -1.f *(relativeVel * ((1 + e) * -1))) / 
			glm::dot(normal, normal * ((1 / mass) + (1 / other->GetMass())));

	glm::vec2 force = normal * j;

	//ApplyForceToActor(other, Vector2Scale(force, 1));
	ApplyForceToActor(other, force * 1.f);
}

void Rigidbody::SetPosition(glm::vec2 pos)
{
	position = pos;
}