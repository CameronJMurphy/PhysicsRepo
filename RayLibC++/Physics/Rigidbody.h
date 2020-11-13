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
	virtual void ResetPosition() override;

	void ResolveCollision(Rigidbody* other);

	const float& GetLinearDrag()const { return linearDrag; }
	const float& GetAngularDrag()const { return angularDrag; }

	const float& GetMass()const { return mass; }

	void SetElasticity(float num) { elasticity = num; }
	float GetElasticity() { return elasticity; }

	glm::vec2 GetVelocity() { return velocity; }
	void SetVelocity(glm::vec2 v) { velocity = v; }

	void SetDeleteOnCollision(bool answer) { deleteOnCollision = answer; }
	bool DeleteOnCollision() { return deleteOnCollision; }
	void SetResetOnCollision(bool answer) { resetOnCollision = answer; }
	bool ResetOnCollision() { return resetOnCollision; }

protected:
	float mass;
	glm::vec2 position;
	glm::vec2 startPos;
	glm::vec2 velocity;
	float angularVelocity;

	float elasticity;

	float linearDrag = 3.f;
	float angularDrag = 0.9f;

	bool deleteOnCollision = false;
	bool resetOnCollision = false;
};
