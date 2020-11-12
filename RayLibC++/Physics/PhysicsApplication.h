#pragma once
#include "Application.h"
#include "PhysicsScene.h"
#include "Analytic.h"



class PhysicsApplication : public Application
{
private:
    PhysicsScene* scene;
    Analytic* analytic;
    Intergrator* intergrator;
public:
    PhysicsApplication();
    ~PhysicsApplication();
    void Update(float deltaTime) override;
    void Draw() override;

};

