#pragma once
#include "PhysicsObject.h"
#include <glm/glm.hpp>
#include <raylib.h>

class Plane : public PhysicsObject
{
public:
    Plane();
    Plane(glm::vec2 normal, float distance);
    ~Plane();


    virtual void FixedUpdate(const glm::vec2& gravity, float fixedTimeStep) {};
    virtual void Draw() override;
    glm::vec2 GetNormal() { return normal; }
    float GetDistance() { return distanceFromOrigin; }

protected:
    glm::vec2 normal;
    float distanceFromOrigin;
};

