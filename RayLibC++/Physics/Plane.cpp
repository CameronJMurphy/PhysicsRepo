#include "Plane.h"


Plane::Plane() : PhysicsObject(ShapeType::PLANE)
{
	normal = glm::vec2{ 0,1 };
	distanceFromOrigin = 0;
}
Plane::Plane(glm::vec2 norm, float distance) : PhysicsObject(ShapeType::PLANE)
{
	normal = norm;
	distanceFromOrigin = distance;
}
Plane::~Plane()
{

}

void Plane::Draw() 
{

	glm::vec2 centerPoint = normal * distanceFromOrigin;

	glm::vec2 parallel{ normal.y,normal.x };
	Color colour{ 255,255,255,0 };
	//define start and end pos
	glm::vec2 start = centerPoint + (parallel * 300.f);
	glm::vec2 end = centerPoint - (parallel * 300.f);

	DrawLine(start.x, start.y, end.x, end.y, colour);
}