#include <iostream>
#include <chrono>
#include <functional>
#include <thread>

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Camera.h"
#include "Player.h"

int main() {
    Game game(sf::VideoMode({1920, 1080}), "RogueLike");
    game.AddGameObject<Player>();
    while(game.IsRunning()) {
        game.ProcessGameFrame();
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
    }

    std::cout << "Programul a terminat executia\n";
    return 0;
}
