#pragma once


#include <set>
#include <string>


#include "IRenderable.h"
#include "UpdateOrder.h"
#include "SFML/Graphics/Transform.hpp"
class GameObject {
protected:
    static int GLOBAL_ID;
    int LOCAL_ID;
    sf::Transform m_transform;
    std::set<GameObject*> m_children;
    std::string m_name;
    GameObject* m_parent;
    UpdateOrder m_updateOrder;

public:
     UpdateOrder getUpdateOrder() const {return m_updateOrder;}




public:

    GameObject(GameObject& parent);

    GameObject( GameObject &parent,std::string name, sf::Transform transform);

    GameObject(std::string name="NONNAME",sf::Transform transform=sf::Transform::Identity);
    virtual ~GameObject();

    virtual void update(float deltaT);
    sf::Transform& getLocalTransform();
    void AddGameObjectToGame(GameObject* gameObject);
     std::set<GameObject*> getChildrens() const {return m_children;}

    int GetId() const {return LOCAL_ID;}
    sf::Transform& getGlobalTransform();

    void AddGameObjectToRenderObjects(IRenderable * game_object);


    template <class T=GameObject>
   T* AddGameObject();
};

template<class T>
T* GameObject::AddGameObject() {
    T* newGameObject = new T();
    auto* renderableComponent = dynamic_cast<IRenderable *>(newGameObject);
    if (renderableComponent) {
        AddGameObjectToRenderObjects(renderableComponent);
    }

    m_children.insert(newGameObject);
    AddGameObjectToGame(dynamic_cast<GameObject*>(newGameObject));
    return newGameObject;
}







