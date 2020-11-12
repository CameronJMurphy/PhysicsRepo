#include "PoolTable.h"


PoolTable::PoolTable(PhysicsScene* ps) : scene{ ps }

{
	PositionBalls();

	//instaniate white ball
	whiteBall = new Sphere(whitePos, glm::vec2{ 0,0 }, 10.f, ballRadius, Color{ 255,255,255,230 });
	scene->AddActor(whiteBall);
	

	//instaniate walls
	auto wall1 = new Plane(glm::vec2{ 0,1 }, 50);
	auto wall2 = new Plane(glm::vec2{ 0,-1 }, -400);
	auto wall3 = new Plane(glm::vec2{ 1,0 }, 50);
	auto wall4 = new Plane(glm::vec2{ -1,0 }, -750);
	walls.push_back(wall1);
	walls.push_back(wall2);
	walls.push_back(wall3);
	walls.push_back(wall4);
	for (int i = 0; i < walls.size(); ++i)
	{
		scene->AddActor(walls[i]);
	}
	float holeRadius = 30.f;
	//instaniate holes
	auto hole1 = new Sphere(glm::vec2{50,50}, glm::vec2{ 0,0 }, 1000000000.f, holeRadius, Color{ 255,0,0,255 });
	auto hole2 = new Sphere(glm::vec2{ 350,50 }, glm::vec2{ 0,0 }, 1000000000.f, holeRadius, Color{ 255,0,0,255 });
	auto hole3 = new Sphere(glm::vec2{700,50}, glm::vec2{ 0,0 }, 1000000000.f, holeRadius, Color{ 255,0,0,255 });
	auto hole4 = new Sphere(glm::vec2{50,400}, glm::vec2{ 0,0 }, 1000000000.f, holeRadius, Color{ 255,0,0,255 });
	auto hole5 = new Sphere(glm::vec2{350,400}, glm::vec2{ 0,0 }, 1000000000.f, holeRadius, Color{ 255,0,0,255 });
	auto hole6 = new Sphere(glm::vec2{ 700,400 }, glm::vec2{ 0,0 }, 1000000000.f, holeRadius, Color{ 255,0,0,255 });


	holes.push_back(hole1);
	holes.push_back(hole2);
	holes.push_back(hole3);
	holes.push_back(hole4);
	holes.push_back(hole5);
	holes.push_back(hole6);
	for (auto h : holes)
	{
		scene->AddActor(h);
	}
	
	

};

void PoolTable::PositionBalls()
{
	auto pos = glm::vec2{ 600,275 };
	int amountOfLines = 5;
	for (int x = 0; x < amountOfLines; ++x)
	{
		for (int y = 5 - x; y > 0; --y)
		{
			pos = glm::vec2{ 600,160 };
			pos.x -= x * (ballRadius * 2);
			pos.y += y * (ballRadius * 2) + (ballRadius * x);
			auto ball = new Sphere(pos, glm::vec2{ 0,0 }, 10.f, ballRadius, Color{ 0,128,255,255 });
			scene->AddActor(ball);
			balls.push_back(ball);
		}
	}
}


void PoolTable::HitHole(Rigidbody* object)
{
	if(object == whiteBall)
	{
		object->SetPosition(whitePos); //reset pos
	}
	else
	{
		object->SetPosition(glm::vec2{ 1000, 1000 }); //offscreen
	}
}