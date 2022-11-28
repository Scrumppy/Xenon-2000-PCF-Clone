#pragma once

#include "EntityComponentSystem.h"

class Level : public Entity
{
public:
	Level();
	~Level();

	virtual void Init();
	virtual void Update();

private:
	float scrollingSpeed = 0.f;

	class SpriteComponent* spriteComponent;
	class TransformComponent* transformComponent;
};