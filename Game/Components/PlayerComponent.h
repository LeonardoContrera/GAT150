#pragma once

#include "Components/Component.h"

namespace nc
{
	class PlayerComponent : public Component
	{
	public:
		virtual bool Create(void* data = nullptr) override;
		virtual void Destroy() override;
		virtual Object* Clone() override { return new PlayerComponent{ *this }; }


		virtual void Update() override;

		void OnCollisionEnter(const Event& event);
		void OnCollisionExit(const Event& event);
	private:
		bool m_killEnemy = false;
	};
}
