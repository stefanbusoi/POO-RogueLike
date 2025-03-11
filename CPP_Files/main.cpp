#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Camera.h"


int main() {
    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 800}), "RogueLike", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    Camera camera(window);


    std::cout << "Fereastra a fost creată\n";

    while(window.isOpen()) {
        bool shouldExit = false;
        while(const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                std::cout << "Fereastra a fost închisă\n";
            }
            else if (event->is<sf::Event::Resized>()) {
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
            }
            else if (event->is<sf::Event::KeyPressed>()) {
                float speed=10;
                const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();

                if (keyPressed->scancode==sf::Keyboard::Scancode::A) {
                    camera.getTransform().translate(sf::Vector2f({-1.0f,0.0f})*speed);
                }
                if (keyPressed->scancode==sf::Keyboard::Scancode::D) {
                    camera.getTransform().translate(sf::Vector2f({1.0f,0.0f})*speed);
                }
                if (keyPressed->scancode==sf::Keyboard::Scancode::W) {
                    camera.getTransform().translate(sf::Vector2f({0.0f,-1.0f})*speed);
                }
                if (keyPressed->scancode==sf::Keyboard::Scancode::S) {
                    camera.getTransform().translate(sf::Vector2f({0.0f,1.0f})*speed);
                }

                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    shouldExit = true;
                }
            }else if (event->is<sf::Event::MouseButtonPressed>()) {
                const auto* keyPressed = event->getIf<sf::Event::MouseButtonPressed>();
                std::cout << "X: " << (keyPressed->position.x)<<",Y: "<<keyPressed->position.y ;
            }
        }
        if(shouldExit) {
            window.close();
            std::cout << "Fereastra a fost inchisă (shouldExit == true)\n";
            break;
        }
        // using namespace std::chrono_literals;
        // std::this_thread::sleep_for(300ms);

        window.clear();

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
        text.setString("MINECRAFT");
        text.setCharacterSize(20);

        camera.draw(text,sf::Transform::Identity);
        window.display();
    }

    std::cout << "Programul a terminat executia\n";
    return 0;
}
