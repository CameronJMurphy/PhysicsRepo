#pragma once

class Application
{
public:
	virtual ~Application() = 0 {};
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;
};


