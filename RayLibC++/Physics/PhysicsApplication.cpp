#include "PhysicsApplication.h"

//set up variables
Sphere* a, * b;
Cue* cue;
PoolTable* pTable;

PhysicsApplication::PhysicsApplication() : scene {new PhysicsScene(glm::vec2{ 0,0.0f }, 0.001f)}
{
	//set up scene
	pTable = new PoolTable(scene);
	cue = new Cue(pTable->GetWhiteBall());
}
PhysicsApplication::~PhysicsApplication()
{
	delete scene;
}
void PhysicsApplication::Update(float deltaTime)
{
	scene->Update(deltaTime);
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !scene->SomethingIsMoving()) //scene->SomthingIsMoving() returns true when things mostly have stopped
	{
		cue->HitBall();
	}
}
void PhysicsApplication::Draw()
{
	// draw pool table
	DrawTexture(pTable->GetTexture(), 0, 0, Color{ 255,255,255,255 }); 
	scene->Draw();
}
