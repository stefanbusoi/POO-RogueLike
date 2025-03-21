#pragma once
#include <ostream>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Player.hpp"

class Camera:public GameObject{

    sf::RenderWindow* m_window;
    Player* m_player=nullptr;
public:
    friend std::ostream & operator<<(std::ostream &os, const Camera &obj);
    ~Camera();
    Camera(GameObject &parent, const std::string &name="NONNAME", const sf::Transform &transform=sf::Transform::Identity);
    sf::Transform& getTransform() ;
    void draw(const sf::Drawable &drawable, const sf::Transform &transform) const;
    void setTransform(const sf::Transform &transform){m_transform=transform;}
    void update(float deltaT) override;

};

