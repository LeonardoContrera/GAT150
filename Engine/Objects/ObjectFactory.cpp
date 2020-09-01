#include "pch.h"
#include "ObjectFactory.h"
#include "Components/PhysicComponents.h"
#include "Components/SpriteComponent.h"
#include "Components/SpriteAnimationComponent.h"
#include "Components/RigidBodyComponent.h"
#include "Components/AudioComponent.h"

namespace nc
{
	void ObjectFactoryImpl::Initialize()
	{
		nc::ObjectFactory::Instance().Register("GameObject", new Creator<GameObject, Object>);
		nc::ObjectFactory::Instance().Register("PhysicsComponents", new Creator<nc::PhysicsComponents, Object>);
		nc::ObjectFactory::Instance().Register("SpriteComponents", new Creator<nc::SpriteComponent, Object>);
		nc::ObjectFactory::Instance().Register("SpriteAnimationComponents", new Creator<nc::SpriteAnimationComponent, Object>);
		nc::ObjectFactory::Instance().Register("RigidBodyComponent", new Creator<nc::RigidBodyComponent, Object>);
		nc::ObjectFactory::Instance().Register("AudioComponent", new Creator<nc::AudioComponent, Object>);
	} 
}
