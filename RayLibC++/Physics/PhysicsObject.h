#pragma once
#include <raylib.h>
#include <glm/glm.hpp>

enum class ShapeType
{
	PLANE = 0,
	SPHERE,
	COUNT
};
class PhysicsObject
{
protected:
	const ShapeType ID;
public:
	
	PhysicsObject(ShapeType type) : ID{ type } {};
	~PhysicsObject() {};
	virtual void FixedUpdate(const glm::vec2& gravity, float fixedTimeStep) = 0;
	virtual void Draw() = 0;
	virtual void ResetPosition() {};

	ShapeType getShapeID() { return ID; };
};
