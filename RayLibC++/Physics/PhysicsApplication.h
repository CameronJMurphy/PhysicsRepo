#pragma once
#include "Application.h"
#include "PhysicsScene.h"


class PhysicsApplication : public Application
{
private:
    PhysicsScene* scene;
public:
    PhysicsApplication();
    ~PhysicsApplication();
    void Update(float deltaTime) override;
    void Draw() override ;
    
};

