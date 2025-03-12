//
// Created by stefa on 3/11/2025.
//

#include "GameObject.h"

#include <iostream>
int GameObject::GLOBAL_ID = 0;
GameObject::GameObject(GameObject &parent):LOCAL_ID(GLOBAL_ID++) {
    m_parent = &parent;
}

GameObject::GameObject():LOCAL_ID(GLOBAL_ID++) {
    m_parent = nullptr;
}

void GameObject::Render(const Camera& camera) {
}

GameObject::~GameObject() {}

void GameObject::update(float deltaT) {
}


void GameObject::start() {
    std::cout<<"Start not implemented";
}

sf::Transform & GameObject::getLocalTransform() {
    return m_transform;
}

sf::Transform & GameObject::getGlobalTransform() {
    if (m_parent)
        return m_parent->getGlobalTransform().combine(m_transform);
    return m_transform;
}
