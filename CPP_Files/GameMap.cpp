//
// Created by stefa on 3/16/2025.
//

#include "GameMap.h"

#include <iostream>

void GameMap::Render(const Camera &camera) {
    for (int i=-30;i<30;i++)
    for (int j=-30;j<30;j++) {
        sf::RectangleShape rect;
        sf::Transform transform=sf::Transform::Identity;
        transform.translate(sf::Vector2f(i,j)*100.0f);
        rect.setSize(sf::Vector2f(100,100));
        rect.setFillColor((i+j)%2==0?sf::Color(0,0,0):sf::Color(20,20,20));
            camera.draw(rect,transform);
    }
}

GameMap::~GameMap() {
}

void GameMap::update(float deltaT) {
    (void)deltaT;
}

void GameMap::start() {
}
