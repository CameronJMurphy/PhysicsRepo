#include "Rocket.h"


Rocket::Rocket(PhysicsScene* psc, glm::vec2 pos, float t, float f)
	: Rigidbody(ShapeType::SPHERE, pos, glm::vec2{0,0}, 0, 20+f)
	, thrust {t}
	, fuel {f}
	, ps {psc}
{

}
void Rocket::FixedUpdate(const glm::vec2& gravity, float fdt)
{
	const float time = 0.25f;
	static float timer = 0;
	timer += fdt;
	//if we have fuel
	while (timer > time && fuel > 0)
	{
		timer -= time;
		//make exhaust actor
		auto exhaust = new Sphere(GetPosition(), glm::vec2{ 0,0 }, thrust, 3, Color{255,255,0,128});
		ps->AddActor(exhaust);
		ApplyForceToActor(exhaust, glm::vec2{0,100} * thrust);
		//update resources
		fuel -= thrust;
		mass -= thrust;
	}
	Rigidbody::FixedUpdate(gravity, fdt);
}



void Rocket::Draw() 
{
	//get positions
	auto temp1 = GetPosition() + glm::vec2{ -5,0 };
	auto temp2 = GetPosition() + glm::vec2{ 5,0 };
	auto temp3 = GetPosition() + glm::vec2{ 0, 15 };
	//switch the raylib vec2
	auto v1 = Vector2{ temp1.x,temp1.y };
	auto v2 = Vector2{ temp2.x,temp2.y };
	auto v3 = Vector2{ temp3.x,temp3.y };
	//Draw
	DrawTriangle(v3, v2, v1, Color{ 0,128,255,255 });
}