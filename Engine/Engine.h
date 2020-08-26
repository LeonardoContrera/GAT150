#pragma once
#include "Graphics/Renderer.h"
#include "Resources/ResourceManager.h"
#include "Input/InputSystem.h"
#include "Physics/PhysicsSystem.h"
#include "Core/Timer.h"
#include "Audio/AudioSystem.h"
#include <vector>

namespace nc
{
	class System;

	class Engine
	{
	public:
		bool StartUp();
		void Shutdown();

		void Update();

		template<typename T>
		inline T* GetSystem();

		nc::FrmeTimer& GetTimer() { return m_timer; }

	protected:
		std::vector<System*> m_system;
		nc::FrmeTimer m_timer;
	};

	template<typename T>
	inline T* Engine::GetSystem()
	{
		T* result{ nullptr };
		for (auto system : m_system)
		{
			result = dynamic_cast<T*>(system);
			if (result) break;
		}
		return result;
	}
}