#include "pch.h"
#include "EnemyComponent.h"
#include "Components/PhysicComponents.h"
#include "Objects/GameObject.h"
#include "Objects/Scene.h"

namespace nc
{
    bool EnemyComponent::Create(void* data)
    {
        m_owner = static_cast<GameObject*>(data);
        return true;
    }

    void EnemyComponent::Destroy()
    {

    }

    void EnemyComponent::Update()
    {
        GameObject* player = m_owner->m_scene->Find("Player");
        if (player)
        {
            Vector2 direction = player->m_transform.position - m_owner->m_transform.position;
            Vector2 force = direction.Normalized() * 10.0f;

            PhysicsComponents* physicsComponent = m_owner->GetComponent<PhysicsComponents>();
            physicsComponent->ApplyForce(force); 
        }
    }
}
