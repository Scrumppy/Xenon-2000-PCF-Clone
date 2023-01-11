#include "PlayerLifeUI.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "LogOutput.h"

PlayerLifeUI::PlayerLifeUI(Vector2D	position)
{
	startPosition = position;
}

PlayerLifeUI::~PlayerLifeUI()
{
	transform = nullptr;
	spriteComponent = nullptr;
}

void PlayerLifeUI::Init()
{
	/*__super::Init();

	AddComponent<TransformComponent>(startPosition.x, startPosition.y);
	transform = &GetComponent<TransformComponent>();

	AddComponent<SpriteComponent>("../Assets/graphics/Ship.bmp", false, false);*/

	AddComponent<TransformComponent>(startPosition.x, startPosition.y);
	transform = &GetComponent<TransformComponent>();
	AddComponent<SpriteComponent>("../Assets/graphics/PULife.bmp", false, false);
	spriteComponent = &GetComponent<SpriteComponent>();
}

void PlayerLifeUI::Update()
{
	__super::Update();

	if (IsActive())
	{
		spriteComponent->ChangeSrcRect(52,52);
		spriteComponent->ChangeDstRect(52, 52);
	}
}
