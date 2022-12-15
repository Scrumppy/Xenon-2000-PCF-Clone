#include "Loner.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "GroupLabels.h"
#include "GameManager.h"
#include "EnemyProjectile.h"

Loner::Loner()
{
	startPosition = Vector2D(1000.f, rand() % 400);
	speed = 0.f;

	fireTimer = 0.f;
	fireTimerMax = 45.f;
}

Loner::~Loner()
{

}

void Loner::Init()
{
	__super::Init();

	AddComponent<TransformComponent>(startPosition.x, startPosition.y);
	AddComponent<SpriteComponent>("../Assets/graphics/LonerA.bmp", true, true);
	GetComponent<SpriteComponent>().Play("EnemyIdle");

	speed = rand() % (int)3.3f + 3;
	transformComponent = &GetComponent<TransformComponent>();
}

void Loner::Update()
{
	if (IsActive())
	{
		__super::Update();

		transformComponent->velocity.x = -1 * speed;

		Fire();

		if (transformComponent->position.x < -50)
		{
			Destroy();
		}
	}
}

void Loner::Fire()
{
	fireTimer += 0.5;

	if (fireTimer >= fireTimerMax)
	{
		GameManager::GetInstance()->InstantiateProjectile<EnemyProjectile>(
			Vector2D(transformComponent->position.x, transformComponent->position.y), 850, 6);

		fireTimer = 0;
	}
}
