#include "pch.h"
#include "Graphics/Texture.h"
#include "Engine.h"
#include "Objects/GameObject.h"
#include "Core/EventManager.h"
#include "Components/PlayerComponent.h"
#include "Components/EnemyComponent.h"
#include "Core/Json.h"
#include "Objects/ObjectFactory.h"
#include "Objects/Scene.h"
#include "TileMap.h"


nc::Engine engine;
nc::Scene scene;

void GameEvent(const nc::Event& event)
{

}

int main(int, char**)
{	
	engine.StartUp();

	nc::ObjectFactory::Instance().Initialize();
	nc::ObjectFactory::Instance().Register("PlayerComponent", new nc::Creator<nc::PlayerComponent, nc::Object>);
	nc::ObjectFactory::Instance().Register("EnemyComponent", new nc::Creator<nc::EnemyComponent, nc::Object>);
	
	nc::EventManager::Instance().Subscribe("PlayerDead", &GameEvent);

	rapidjson::Document document;
	nc::json::Load("scene.txt", document);
	scene.Create(&engine);
	scene.Read(document);

	nc::TileMap tileMap;
	nc::json::Load("tileMap.txt", document);
	tileMap.Read(document);
	tileMap.Create(&scene);

	//for (size_t i = 0; i < 10; i++)
	//{
	//	nc::GameObject* gameObject = nc::ObjectFactory::Instance().Create<nc::GameObject>("ProtoCoin");
	//	gameObject->m_transform.position = nc::Vector2{ nc::random(0, 800), nc::random(200, 400) };
	//	//gameObject->m_transform.angle = nc::random(0, 360);
	//	scene.AddGameObject(gameObject);
	//}

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		//update
		engine.Update();
		scene.Update();

		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == nc::InputSystem::eButtonState::PRESSED)
		{
			quit = true;
		}

		// draw
		engine.GetSystem<nc::Renderer>()->BeginFrame();
		scene.Draw();

		engine.GetSystem<nc::Renderer>()->EndFrame();
	}
	
	scene.Destroy();
	engine.Shutdown();

	return 0;
}
