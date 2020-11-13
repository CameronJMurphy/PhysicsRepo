#include "PhysicsApplication.h"
#include "Sphere.h"
#include "Plane.h"
#include "Rocket.h"
#include <iostream>
#include "PoolTable.h"
#include "Cue.h"

Sphere* a, * b;
Cue* cue;
PoolTable* pTable;
PhysicsApplication::PhysicsApplication() : scene {new PhysicsScene(glm::vec2{ 0,0.0f }, 0.001f)}
{
	pTable = new PoolTable(scene);
	cue = new Cue(pTable->GetWhiteBall());
	/*a = new Sphere(glm::vec2{ 100, 205 }, glm::vec2{ -50,0 },1.f, 15.f, Color{ 255,128,0,255 });
	b = new Sphere(glm::vec2{ 30, 200 }, glm::vec2{50,0},1.f, 15.f, Color{ 0,128,255,255 });
	auto c = new Plane(glm::vec2{ 0,1 }, 300);
	scene->AddActor(a);
	scene->AddActor(b);
	scene->AddActor(c);

	scene->RegisterCollision([](const PhysicsObject* a, const PhysicsObject* b) {std::cout << "Collision" << std::endl; });*/

	//scene->AddActor(new Rocket(scene, glm::vec2{300,200}, 2.f, 40.f));

	/*analytic = new Analytic(scene->GetGravity(), glm::vec2{ 30,430 }, glm::vec2{40,-40},0,10);
	intergrator = new Intergrator(a, scene->GetGravity(),0,20,0.01f);*/
}
PhysicsApplication::~PhysicsApplication()
{
	delete scene;
}
void PhysicsApplication::Update(float deltaTime)
{
	scene->Update(deltaTime);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !scene->SomethingIsMoving())
	{
		cue->HitBall();
	}
	static float timer = 0;
	timer += deltaTime;
	if (timer > 9)
	{
		timer = 0;
	}
	/*auto p = analytic->Analyze(timer);
	DrawCircle(p.x, p.y, 6, Color{ 255,0,0,255 });*/
}
void PhysicsApplication::Draw()
{
	scene->Draw();

	//analytic->Draw();

	//intergrator->Draw();
}
