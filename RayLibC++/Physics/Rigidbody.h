#pragma once
#include "PhysicsObject.h"

class Rigidbody : public PhysicsObject
{
public:
	Rigidbody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float rotation, float mass);
	~Rigidbody();


	virtual void FixedUpdate(const glm::vec2& gravity, float fixedTimeStep) override;

	void ApplyForce(glm::vec2 force);
	void ApplyForceToActor(Rigidbody* actor2, glm::vec2 force);

	void SetPosition(glm::vec2 pos);
	glm::vec2 GetPosition() { return position; } ;


	void ResolveCollision(Rigidbody* other);

	const float& GetLinearDrag()const { return linearDrag; }
	const float& GetAngularDrag()const { return angularDrag; }

	const float& GetMass()const { return mass; }

	void SetElasticity(float num) { elasticity = num; }
	float GetElasticity() { return elasticity; }

	glm::vec2 GetVelocity() { return velocity; }

protected:
	float mass;
	glm::vec2 position;
	glm::vec2 velocity;
	float angularVelocity;

	float elasticity;

	float linearDrag = 2.f;
	float angularDrag = 0.9f;
};
