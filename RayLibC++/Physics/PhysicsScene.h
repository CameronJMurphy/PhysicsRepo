#pragma once
#include <vector>
#include <raylib.h>
#include <functional>
#include <glm/glm.hpp>
#include "Sphere.h"
#include "Plane.h"
#include "PhysicsObject.h"
#include <iostream>

class PhysicsObject;

class PhysicsScene
{
public:
	PhysicsScene(glm::vec2 grav, float tstep);
	~PhysicsScene();

	void AddActor(PhysicsObject* actor);
	void RemoveActor(PhysicsObject* actor);
	void ProcessPendingRemovals();

	void Update(float deltaTime);
	void Draw();

	void SetTimeStep(const float _timeStep);
	float GetTimeStep() const;

	void CheckForCollision();
	static bool Plane2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool Plane2Sphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool Sphere2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool Sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2);

	using CollisionFn = std::function<void(const PhysicsObject*, const const PhysicsObject*)>;

	std::vector<CollisionFn> collisionEvents;
	void RegisterCollision(CollisionFn fn)
	{
		collisionEvents.push_back(fn);
	}

	void SetGravity(const glm::vec2 g) { gravity = g; }
	glm::vec2 GetGravity() const
	{
		return gravity;
	}
	bool SomethingIsMoving();
	static void SphereInteraction(Sphere* sphere1, Sphere* sphere2);

protected:
	glm::vec2 gravity;
	float timeStep;
	std::vector<PhysicsObject*> actors;
	std::vector<PhysicsObject*> pendingAdds;

	std::vector<PhysicsObject*> pendingRemovals;
};