#pragma once

#include <map>
#include <string>
#include <unordered_map>


#include "SFML/Graphics/Transform.hpp"


class GameObject {
protected:
    static int GLOBAL_ID;
    int LOCAL_ID;
    sf::Transform m_transform;
    std::unordered_map<int,GameObject*> m_children;
    std::string m_name;
    GameObject* m_parent;


public:

    GameObject(GameObject& parent);

    GameObject( GameObject &parent,std::string name, sf::Transform transform);

    GameObject(std::string name="NONNAME",sf::Transform transform=sf::Transform::Identity);
    virtual void Render();
    virtual ~GameObject();
    // GameObject(GameObject& parent): LOCAL_ID(GLOBAL_ID++) {
  //      m_parent.emplace(parent);
  //
  // }
    virtual void update(float deltaT);
    virtual void start();
    sf::Transform& getLocalTransform();

    std::unordered_map<int, GameObject *> getChildrens() const {return m_children;}

    int GetId() const {return LOCAL_ID;}
    sf::Transform& getGlobalTransform();
    template <typename T>

    T* AddGameObject();
};

template<typename T>
T* GameObject::AddGameObject() {
    T* newGameObject = new T();
    m_children.insert(std::pair<int,GameObject*>(newGameObject->GetId(),newGameObject));
    //TODO:Fix this
    //  Game::getInstance()->getGameObjects().insert(std::pair<int,GameObject*>(newGameObject->GetId(),newGameObject));
    return newGameObject;
}








