#pragma once
#include "Application.h"
#include "PhysicsScene.h"
#include "Analytic.h"
#include "Sphere.h"
#include "Plane.h"
#include "Rocket.h"
#include <iostream>
#include "PoolTable.h"
#include "Cue.h"



class PhysicsApplication : public Application
{
private:
    PhysicsScene* scene;
public:
    PhysicsApplication();
    ~PhysicsApplication();
    void Update(float deltaTime) override;
    void Draw() override;

};

