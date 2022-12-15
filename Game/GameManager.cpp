#include "GameManager.h"
#include "Vector2D.h"
#include "EntityComponentSystem.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include <iostream>
#include "Projectile.h"
#include "Loner.h"
#include "Rusher.h"
#include "Level.h"
#include "Debris.h"

GameManager* GameManager::m_instance = nullptr;
Manager* GameManager::m_manager = nullptr;

GameManager::~GameManager()
{
	delete m_manager;
	delete m_instance;
}

Manager* GameManager::GetManager()
{
	return m_manager;
}

void GameManager::Update()
{
	SpawnEnemies();
	SpawnDebris();
}

void GameManager::CreateLevel()
{
	m_manager->CreateEntity<Level>();
}

void GameManager::SpawnEnemies()
{
	lonerSpawnTimer += 0.5f;
	rusherSpawnTimer += +0.5f;

	if (lonerSpawnTimer >= lonerSpawnTimerMax)
	{
		enemiesToSpawn = rand() % 2 + 1;

		for (int i = 0; i < enemiesToSpawn; ++i)
		{
			GameEngine::manager.CreateEntity<Loner>();
		}

		lonerSpawnTimer = 0.f;
	}

	if (rusherSpawnTimer >= rusherSpawnTimerMax)
	{
		enemiesToSpawn = rand() % 5 + 3;

		for (int i = 0; i < enemiesToSpawn; ++i)
		{
			GameEngine::manager.CreateEntity<Rusher>();
		}

		rusherSpawnTimer = 0.f;
	}
}

void GameManager::SpawnDebris()
{
	debrisSpawnTimer += 0.5f;

	if (debrisSpawnTimer >= debrisSpawnTimerMax)
	{
		m_manager->CreateEntity<Debris>(true);
		debrisSpawnTimerMax = 150 + (rand() % (200 - 150) + 1);
		debrisSpawnTimer = 0.f;
	}
}
