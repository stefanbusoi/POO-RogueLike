//
// Created by stefa on 3/11/2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <map>
#include <vector>

#include "SFML/Graphics/Transform.hpp"


class GameObject {
protected:
    static int GLOBAL_ID;
    const int LOCAL_ID;
    sf::Transform m_transform;
    std::map<int,GameObject*> m_children;
    GameObject* m_parent;
public:
    GameObject(GameObject& parent): LOCAL_ID(GLOBAL_ID++) {
  //      m_parent.emplace(parent);

    }
    sf::Transform& getLocalTransform();

    sf::Transform& getGlobalTransform();
};



#endif //GAMEOBJECT_H
