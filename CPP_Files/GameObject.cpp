//
// Created by stefa on 3/11/2025.
//

#include "GameObject.h"

#include <iostream>
#include <utility>

#include "Game.h"
int GameObject::GLOBAL_ID = 0;
GameObject::GameObject(GameObject &parent,std::string name,sf::Transform transform):
    LOCAL_ID(GLOBAL_ID++),
    m_transform(transform),
    m_name(std::move(name)),
    m_parent(&parent)
   {}


GameObject::GameObject(std::string name, sf::Transform transform): LOCAL_ID(GLOBAL_ID++),
                                                                   m_transform(transform),
                                                                   m_name(std::move(name)),
                                                                   m_parent(nullptr) {}




GameObject::~GameObject() {}



void GameObject::update(float deltaT) {
    std::cout<<"Start not implemented";
}

sf::Transform & GameObject::getLocalTransform() {
    return m_transform;
}

void GameObject::AddGameObjectToGame(GameObject *gameObject) {
    Game::getInstance()->getGameObjects().insert(gameObject);


}

sf::Transform & GameObject::getGlobalTransform() {
    if (m_parent)
        return m_parent->getGlobalTransform().combine(m_transform);
    return m_transform;
}

void GameObject::AddGameObjectToRenderObjects(IRenderable *game_object) {
    Game::getInstance()->getRenderOrder().insert(game_object);

}

