#pragma once
#include "Component.h"
#include "Math/Vector2.h"

namespace nc
{
	class PhysicsComponents : public Component
	{
	public:

		virtual bool Create(void* data = nullptr) override;
		virtual void Destroy() override;
		virtual Object* Clone() override { return new PhysicsComponents{ *this }; }


		virtual void Update() override;

		virtual void ApplyForce(const Vector2& force) { m_force = force; }

	protected:
		Vector2 m_velocity;
		Vector2 m_force;
		float m_drag{ 0.94f };
	};
}