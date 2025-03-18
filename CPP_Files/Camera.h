#pragma once
#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Player.h"

class Camera:public GameObject{
    sf::Transform m_transform=sf::Transform::Identity;
    sf::RenderWindow* m_window;
    Player* m_player=nullptr;
public:
    explicit Camera();

    sf::Transform& getTransform() ;
    void draw(const sf::Drawable &drawable, sf::Transform transform) const;
    void setTransform(const sf::Transform &transform){m_transform=transform;}
    void update(float deltaT) override;

};

