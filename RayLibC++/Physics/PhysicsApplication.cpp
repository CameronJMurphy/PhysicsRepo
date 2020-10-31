#include "PhysicsApplication.h"
#include "Sphere.h"
#include "Plane.h"
#include "Rocket.h"

Sphere* a, * b;
PhysicsApplication::PhysicsApplication() : scene {new PhysicsScene(glm::vec2{ 0,0 }, 0.01f)}
{
	
	a = new Sphere(glm::vec2{ 470, 250 }, glm::vec2{ 5,0 }, 1, 10, Color{ 255,128,0,255 });
	b = new Sphere(glm::vec2{ 530, 250 }, glm::vec2{5,0},1, 10, Color{ 0,128,255,255 });
	auto c = new Plane(glm::vec2{ 0,1 }, 300);
	scene->AddActor(a);
	scene->AddActor(b);

	scene->AddActor(new Rocket(scene, glm::vec2{300,200}, 2.f, 40.f));
}
PhysicsApplication::~PhysicsApplication()
{
	delete scene;
}
void PhysicsApplication::Update(float deltaTime)
{
	scene->Update(deltaTime);
	if (IsKeyPressed(' '))
	{
		a->ApplyForceToActor(b,glm::vec2(20.f,0.f));
	}
}
void PhysicsApplication::Draw()
{
	scene->Draw();
}