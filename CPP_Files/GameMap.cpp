//
// Created by stefa on 3/16/2025.
//

#include "GameMap.hpp"

#include <iostream>

#include "Game.hpp"

void GameMap::Render() {
    Camera &camera=Game::getInstance()->getCamera();
    for (int i=-5;i<5;i++)
    for (int j=-5;j<5;j++) {
        sf::RectangleShape rect;
        sf::Transform transform=sf::Transform::Identity;
        transform.translate(sf::Vector2f(i,j)*100.0f);
        rect.setSize(sf::Vector2f(100,100));
        rect.setFillColor((i+j)%2==0?sf::Color(0,0,0):sf::Color(20,20,20));
            camera.draw(rect,transform);
    }
}

GameMap::GameMap(GameObject &parent, const std::string &name, const sf::Transform &transform) {
    m_parent=&parent;
    m_name=name;
    m_transform=transform;
    m_renderOrder=RenderOrder::Terrain;
    m_updateOrder=UpdateOrder::Default;
}

GameMap::~GameMap() {
}

void GameMap::update(float deltaT) {
    (void)deltaT;
}
