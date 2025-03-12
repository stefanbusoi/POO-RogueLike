//
// Created by stefa on 3/11/2025.
//

#include "Game.h"
Game::Game(const sf::VideoMode video_mode, std::string Title): title_(std::move(Title)) ,camera(Camera(window)){
    window.create(video_mode, Title, sf::State::Fullscreen);
    std::cout << "Fereastra a fost creata\n";

}

bool Game::IsRunning() const {
    return window.isOpen();

}

void Game::Exit() {
    window.close();
    std::cout << "Fereastra a fost inchisa\n";
}
//TODO: edit this
float Game::ProcessGameFrame() {
    sf::Time deltaTime = clock.getElapsedTime();
    clock.restart();
    for (const auto& [i, j]:gameObjects) {
        j->update(deltaTime.asSeconds());
    }
    RenderAll();
    return  deltaTime.asSeconds();
}


