#include "pch.h"
#include "Engine.h"
#include <time.h>

namespace nc 
{
    bool Engine::StartUp()
    {
        srand(static_cast<unsigned int>(time(nullptr)));

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
            return false;
        }

        m_system.push_back(new Renderer);
        m_system.push_back(new InputSystem);
        m_system.push_back(new ResourceManager);
        m_system.push_back(new PhysicsSystem);
        m_system.push_back(new AudioSystem);

        for (auto system : m_system)
        {
            system->Startup();
        }

        GetSystem<Renderer>()->Create("GAT150", 800, 600);

        return true;
    }

    void Engine::Shutdown()
    {
        for (auto system : m_system)
        {
            system->Shutdown();
            delete system;
        }
        m_system.clear();

        SDL_Quit();
    }

    void Engine::Update()
    {
        m_timer.Tick();
        for (auto system : m_system)
        {
            system->Update();
        }
    }
}