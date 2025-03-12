//
// Created by stefa on 3/12/2025.
//

#include "Player.h"

void Player::update(float deltaT)  {
    float speed=500;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
        m_transform.translate(sf::Vector2f({-1.0f,0.0f})*deltaT*speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
        m_transform.translate(sf::Vector2f({1.0f,0.0f})*deltaT*speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
        m_transform.translate(sf::Vector2f({0.0f,-1.0f})*deltaT*speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
        m_transform.translate(sf::Vector2f({0.0f,1.0f})*deltaT*speed);
    }
}

Player::~Player() {
}

void Player::Render(const Camera& camera) {
    sf::CircleShape shape(40.f);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(sf::Vector2f(-20, -20));
    sf::Transform transform=this->m_transform;
    transform.translate(sf::Vector2f(40,40));
    camera.draw(shape,transform);
    sf::Font font("../Minecraft.ttf");

    sf::Text text(font);
    text.setString("CEVA");
    text.setPosition(sf::Vector2f(0,-30));
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);

    camera.draw(text,m_transform);
}

