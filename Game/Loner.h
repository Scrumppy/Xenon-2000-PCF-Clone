#pragma once

#include "Pawn.h"
#include "Vector2D.h"

class Loner : public Pawn
{
public:
	Loner();
	~Loner();

	virtual void Init();
	virtual void Update();

	virtual void Fire();

private:
	Vector2D startPosition;
	Vector2D playerPosition;
	float speed;

	class TransformComponent* transformComponent = nullptr;
};