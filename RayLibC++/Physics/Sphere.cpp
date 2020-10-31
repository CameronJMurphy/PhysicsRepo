#include "Sphere.h"


Sphere::Sphere(glm::vec2 pos, glm::vec2 vel, float mass, float r, Color c) 
	: Rigidbody(ShapeType::SPHERE, pos,vel,0,mass)
	,radius{r}
	,colour{c}
{

}
Sphere::~Sphere()
{

}

void Sphere::Draw() 
{
	DrawCircle(position.x, position.y, radius, colour);
}
