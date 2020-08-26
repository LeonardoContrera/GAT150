#include "pch.h"
#include "PhysicComponents.h"
#include "Objects/GameObject.h"

namespace nc
{
    bool PhysicsComponents::Create(void* data)
    {
        m_owner = static_cast<GameObject*>(data);

        return true;
    }

    void PhysicsComponents::Destroy()
    {
    }

    void PhysicsComponents::Update()
    {
        m_velocity = m_velocity + m_force * m_owner->m_engine->GetTimer().DeltaTime();
        m_velocity = m_velocity * m_drag;
        m_owner->m_transform.position = m_owner->m_transform.position + m_velocity * m_owner->m_engine->GetTimer().DeltaTime();

    }
}