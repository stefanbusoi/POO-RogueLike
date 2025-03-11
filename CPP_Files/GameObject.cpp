//
// Created by stefa on 3/11/2025.
//

#include "GameObject.h"

sf::Transform & GameObject::getLocalTransform() {
    return m_transform;
}

sf::Transform & GameObject::getGlobalTransform() {
    if (m_parent)
        return m_parent->getGlobalTransform().combine(m_transform);
    return m_transform;
}
