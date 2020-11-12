#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include <iostream>
#include "Sphere.h"
#include "Plane.h"

PhysicsScene::PhysicsScene(glm::vec2 gr = glm::vec2{ 0,0 }, float t = 0.01f) : timeStep{ t }, gravity{ gr }
{

}

PhysicsScene::~PhysicsScene() 
{
	for (PhysicsObject* po : actors)
	{
		delete po;
	}
}

void PhysicsScene::AddActor(PhysicsObject* actor)
{
	pendingAdds.push_back(actor);
	//actors.push_back(actor);
}
void PhysicsScene::RemoveActor(PhysicsObject* actor)
{
	pendingRemovals.push_back(actor);
}

void PhysicsScene::ProcessPendingRemovals()
{
	auto it = actors.end();
	for (auto a : pendingRemovals)
	{
		auto i = std::remove(actors.begin(), actors.end(), a);
		if (i != actors.end())
		{
			it = i;
		}
		
	}
	/*actors.erase(it, actors.end());
	pendingRemovals.clear();*/
}
void PhysicsScene::Update(float deltaTime)
{
	static float accumulatedTime = 0.0f;
	accumulatedTime += deltaTime;

	pendingAdds.reserve(1);

	//update actors in scene
	while (accumulatedTime >= timeStep)
	{
		for (auto po : actors)
		{
			po->FixedUpdate(gravity, timeStep);
			CheckForCollision();
		}
		accumulatedTime -= timeStep;
	}
	//add pending adds to the actors list
	actors.reserve(actors.size() + pendingAdds.size());
	actors.insert(actors.end(), pendingAdds.begin(), pendingAdds.end());
	pendingAdds.clear();
}
void PhysicsScene::Draw()
{
	for (auto po : actors)
	{
		po->Draw();
	}
}

void PhysicsScene::SetTimeStep(const float _timeStep) 
{
	timeStep = _timeStep;
}
float PhysicsScene::GetTimeStep() const 
{ 
	return timeStep; 
}

typedef bool(*fn)(PhysicsObject*, PhysicsObject*);

static fn collisionFunctionArray[] = {
	PhysicsScene::Plane2Plane, PhysicsScene::Plane2Sphere,
	PhysicsScene::Sphere2Plane, PhysicsScene::Sphere2Sphere
};

void PhysicsScene::CheckForCollision()
{
	int actorCount = actors.size();

	for (int outer = 0; outer < actorCount - 1; outer++)
	{
		for (int inner = outer + 1; inner < actorCount; inner++)
		{
			PhysicsObject* object1 = actors[outer];
			PhysicsObject* object2 = actors[inner];
			int shapeID1 = (int)object1->getShapeID();
			int shapeID2 = (int)object2->getShapeID();

			int functionId = (shapeID1 * (int)ShapeType::COUNT) + shapeID2;
			fn collisionFunctionPtr = collisionFunctionArray[functionId];


			if (collisionFunctionPtr != nullptr)
			{
				if (collisionFunctionPtr(object1, object2) == true)
				{
					for (CollisionFn func : collisionEvents)
					{
						func(object1, object2);
					}
				}
			}
			else
			{
				std::cout << "Include objects not implemented in collision function array;";
			}
		}
	}
}
bool PhysicsScene::Plane2Plane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return false;
}
bool PhysicsScene::Plane2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return Sphere2Plane(obj2, obj1);
}
bool PhysicsScene::Sphere2Plane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere = dynamic_cast<Sphere*>(obj1);
	Plane* plane = dynamic_cast<Plane*>(obj2);

	if (sphere != nullptr && plane != nullptr)
	{
		glm::vec2 collisionNormal = plane->GetNormal();
		float sphereToPlane = glm::dot(sphere->GetPosition(), plane->GetNormal()) - plane->GetDistance();

		if (sphereToPlane < 0)
		{
			collisionNormal *= -1; 
			sphereToPlane *= -1;
		}

		float intersection = sphere->GetRadius() - sphereToPlane;
		if (intersection > 0)
		{
			glm::vec2 planeNormal = plane->GetNormal();
			if (sphereToPlane < 0)
			{
				
				planeNormal *= -1;
			}

			
			glm::vec2 forceVector = planeNormal * (-1 * sphere->GetMass() * (glm::dot(planeNormal, sphere->GetVelocity())));

			sphere->ApplyForce(forceVector * 2.f);
			
			sphere->SetPosition(sphere->GetPosition() + (collisionNormal * (intersection * 1.f)));
			
			return true;
		}
	}
	return false;
}

bool PhysicsScene::Sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere1 = dynamic_cast<Sphere*>(obj1);
	Sphere* sphere2 = dynamic_cast<Sphere*>(obj2);

	if (sphere1 != nullptr && sphere2 != nullptr)
	{
		glm::vec2 delta = sphere2->GetPosition() - sphere1->GetPosition();
		float distance = glm::distance(sphere1->GetPosition(), sphere2->GetPosition());
		float intersection = sphere1->GetRadius() + sphere2->GetRadius() - distance;


		if (intersection > 0)
		{
			sphere1->ResolveCollision(sphere2);
			glm::vec2 collisionNormal = glm::normalize(delta);
			glm::vec2 seperationVector = collisionNormal * (intersection * 0.5f);
			sphere1->SetPosition(sphere1->GetPosition() - seperationVector);
			sphere2->SetPosition(sphere2->GetPosition() + seperationVector);
			
			return true;			
		}
	}
	return false;
}