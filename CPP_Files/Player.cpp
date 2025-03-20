#include "Camera.hpp"
#include "Player.hpp"
#include "Game.hpp"


void Player::update(float deltaT)  {
    float SpeedConst=500;

    sf::Vector2f speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space)) {
        speed+=sf::Vector2f({-1.0f,0.0f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
       speed+=sf::Vector2f({-1.0f,0.0f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
        speed+=sf::Vector2f({1.0f,0.0f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
        speed+=sf::Vector2f({0.0f,-1.0f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
        speed+=sf::Vector2f({0.0f,1.0f});
    }
    if (speed.x!=0||speed.y!=0) {
        speed=speed.normalized();
        speed=speed*deltaT*SpeedConst;
    }

    m_transform.translate(speed);


}

Player::~Player() = default;

void Player::Render() {
    const Camera& camera=Game::getInstance()->getCamera();
    sf::CircleShape shape(40.f);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(sf::Vector2f(-20,-20));
    sf::Transform transform=this->m_transform;

    camera.draw(shape,transform);
    sf::Font font("../Minecraft.ttf");

    sf::Text text(font);
    text.setString("STEFAN");
    text.setPosition(sf::Vector2f(-20,-47));
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);

    camera.draw(text,m_transform);
}

Player::Player(GameObject &parent, const std::string &name, const sf::Transform &transform): GameObject(parent, name, transform) {
    m_renderOrder=RenderOrder::Player;
    m_updateOrder=UpdateOrder::Default;
}

