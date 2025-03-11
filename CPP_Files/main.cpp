#include <iostream>
#include <chrono>
#include <functional>
#include <thread>

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Camera.h"

int main() {
    Game game(sf::VideoMode({1920, 1080}), "RogueLike");

    Camera camera(game.getWindow());

    while(game.IsRunning()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
            camera.getTransform().translate(sf::Vector2f({-1.0f,0.0f})*0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
            camera.getTransform().translate(sf::Vector2f({1.0f,0.0f})*0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
            camera.getTransform().translate(sf::Vector2f({0.0f,-1.0f})*0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
            camera.getTransform().translate(sf::Vector2f({0.0f,1.0f})*0.1f);
        }
        while(const std::optional event = game.getWindow().pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                game.Exit();
            }
            else if (event->is<sf::Event::Resized>()) {
                std::cout << "New width: " << game.getWindow().getSize().x << '\n'
                          << "New height: " << game.getWindow().getSize().y << '\n';
            }
            else if (event->is<sf::Event::KeyPressed>()) {
                const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    game.Exit();
                }
            }else if (event->is<sf::Event::MouseButtonPressed>()) {
                const auto* keyPressed = event->getIf<sf::Event::MouseButtonPressed>();
                std::cout << "X: " << (keyPressed->position.x)<<",Y: "<<keyPressed->position.y ;
            }
        }

        game.getWindow().clear();

        sf::CircleShape shape(40.f);
        shape.setFillColor(sf::Color(100, 250, 50));
        shape.setPosition(sf::Vector2f(-20, -20));
        sf::Transform transform=sf::Transform::Identity;
        transform.translate(sf::Vector2f(40,40));
        camera.draw(shape,transform);
        sf::Font font("../Minecraft.ttf");
        sf::Text text(font);
        text.setPosition(sf::Vector2f(0,0));
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(20);

        camera.draw(text,sf::Transform::Identity);
        game.getWindow().display();
    }

    std::cout << "Programul a terminat executia\n";
    return 0;
}
