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
#include "Drone.h"
#include "CompanionPickup.h"
#include "WeaponPickup.h"
#include "ShieldPickup.h"
#include "BigAsteroid.h"
#include "MetalAsteroid.h"
#include "PlayerLifeUI.h"
#include <LogOutput.h>
#include "Player.h"

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
	SpawnDebris();
	SpawnEnemies();
	SpawnPickups();
}

void GameManager::CreateLevel()
{	
	m_manager->CreateEntity<Level>();
	player = m_manager->CreateEntity<Player>();
}

void GameManager::SpawnEnemies()
{
	lonerSpawnTimer += 0.5f;
	rusherSpawnTimer += +0.5f;
	droneSpawnTimer += 0.5f;
	asteroidSpawnTimer += 0.5f;

	if (lonerSpawnTimer >= lonerSpawnTimerMax)
	{
		enemiesToSpawn = rand() % 2 + 1;

		for (int i = 0; i < enemiesToSpawn; ++i)
		{
			m_manager->CreateEntity<Loner>();
		}

		lonerSpawnTimer = 0.f;
	}

	if (rusherSpawnTimer >= rusherSpawnTimerMax)
	{
		enemiesToSpawn = rand() % 5 + 3;

		for (int i = 0; i < enemiesToSpawn; ++i)
		{
			m_manager->CreateEntity<Rusher>();
		}

		rusherSpawnTimer = 0.f;
	}

	if (asteroidSpawnTimer >= asteroidSpawnTimerMax)
	{
		 int asteroidsToSpawn = rand() % 1 + 2;

		for (int i = 0; i < asteroidsToSpawn; ++i)
		{
			m_manager->CreateEntity<BigAsteroid>();
			m_manager->CreateEntity<MetalAsteroid>();
		}

		asteroidSpawnTimer = 0.f;
	}

	/*if (droneSpawnTimer >= droneSpawnTimerMax)
	{
		enemiesToSpawn = 6;

		for (int i = 0; i < enemiesToSpawn; ++i)
		{

			GameEngine::manager.CreateEntity<Drone>();
		}

		droneSpawnTimer = 0.f;
	}*/

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

void GameManager::SpawnPickups()
{
	pickupSpawnTimer += 0.5f;

	if (pickupSpawnTimer >= pickupSpawnTimerMax)
	{
		pickupsToSpawn = 1;

		for (int i = 0; i < pickupsToSpawn; ++i)
		{
			//GameEngine::manager.CreateEntity<CompanionPickup>();
			m_manager->CreateEntity<WeaponPickup>();
			m_manager->CreateEntity<ShieldPickup>();
		}

		pickupSpawnTimer = 0.f;
	}
}

void GameManager::LoadUI()
{
	for (int i = 0; i < 3; ++i)
	{
		playerLives.push_back(m_manager->CreateEntity<PlayerLifeUI>(Vector2D(20 + (i * 60), 700)));
	}

	DebugLog(LogMessage::WARNING, "Loaded Player Life UI");
}

void GameManager::EraseLife()
{
	if (playerLives.size() > 0)
	{
		playerLives.back()->Destroy();
		playerLives.pop_back();
	}
}

