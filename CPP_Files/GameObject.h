#pragma once

#include <map>

#include "Camera.h"
#include "SFML/Graphics/Transform.hpp"


class GameObject {
protected:
    static int GLOBAL_ID;
    int LOCAL_ID;
    sf::Transform m_transform;
    std::map<int,GameObject*> m_children;
    GameObject* m_parent;

public:

    GameObject(GameObject& parent);
    GameObject();
    virtual void Render(const Camera& camera);
    virtual ~GameObject();
    // GameObject(GameObject& parent): LOCAL_ID(GLOBAL_ID++) {
  //      m_parent.emplace(parent);
  //
  // }
    virtual void update(float deltaT);
    virtual void start();
    sf::Transform& getLocalTransform();
    int GetId() const {return LOCAL_ID;}
    sf::Transform& getGlobalTransform();
};








