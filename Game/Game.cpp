#include "GameEngine.h"
#include "Player.h"
#include "LevelManager.h"
#include <iostream>

int main(int argc, char ** argv)
{
    GameEngine engine;

    //Engine Init
    engine.Init("Xenon 2000 - Engenho Irreal 5", 1024, 800, false);

    /*
    * Declare variables / objects here --------------------------
    */

    GameEngine::manager.CreateEntity<Player>();

    LevelManager::GetInstance()->SpawnEnemies();

    /*
    * -------------------------------------------------
    */
     
    //Engine Loop
    engine.Run();

    return 0;
}
