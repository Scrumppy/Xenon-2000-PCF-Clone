#include "LevelManager.h"
#include "GameEngine.h"
#include "Vector2D.h"
#include "EntityComponentSystem.h"
#include "Projectile.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "GroupLabels.h"
#include <iostream>
#include "../Game/Loner.h"
#include "../Game/Rusher.h"
#include "../Game/Level.h"
#include "../Game/Debris.h"

LevelManager* LevelManager::m_instance = nullptr;
Manager* LevelManager::m_manager = nullptr;


LevelManager::LevelManager()
{
	m_manager = &GameEngine::manager;

	lonerSpawnTimer = 0.f;
	lonerSpawnTimerMax = rand() % 110 + 100;

	rusherSpawnTimer = 0.f;
	rusherSpawnTimerMax = rand() % 190 + 205;

	debrisSpawnTimer = 800.f;
	debrisSpawnTimerMax = 800.f;

	enemiesToSpawn = 0;
}

LevelManager::~LevelManager()
{
	delete m_manager;
	delete m_instance;
}

Manager* LevelManager::GetManager()
{
	return m_manager;
}

void LevelManager::Update()
{
	//SpawnEnemies();
	SpawnDebris();
}

void LevelManager::CreateProjectile(Vector2D position, float projectileRange, float projectileSpeed)
{
	m_manager->CreateEntity<Projectile>(position, projectileRange, projectileSpeed);
}

void LevelManager::CreateLevel()
{
	m_manager->CreateEntity<Level>();
}

void LevelManager::SpawnEnemies()
{
	lonerSpawnTimer += 0.5f;
	rusherSpawnTimer += + 0.5f;

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

void LevelManager::SpawnDebris()
{
	debrisSpawnTimer += 0.5f;

	if (debrisSpawnTimer >= debrisSpawnTimerMax)
	{
		m_manager->CreateEntity<Debris>();
		debrisSpawnTimer = 0.f;
	}
}

