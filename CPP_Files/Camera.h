#pragma once
#include <SFML/Graphics.hpp>

class Camera{
    sf::Transform m_transform=sf::Transform::Identity;
    sf::RenderWindow& m_window;
public:
    explicit Camera(sf::RenderWindow& window):m_window(window){};

    sf::Transform& getTransform() ;
    void draw(const sf::Drawable &drawable, sf::Transform transform) const;
    void setTransform(const sf::Transform &transform){m_transform=transform;}


};
