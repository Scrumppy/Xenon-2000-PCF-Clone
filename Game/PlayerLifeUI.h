#pragma once

#include "UI.h"
#include "Vector2D.h"

class TransformComponent;
class SpriteComponent;

class PlayerLifeUI : public UI
{
public:
	PlayerLifeUI(Vector2D position);
	~PlayerLifeUI();

	virtual void Init();
	virtual void Update();

private:
	Vector2D startPosition;
	TransformComponent* transform;
	SpriteComponent* spriteComponent;
};