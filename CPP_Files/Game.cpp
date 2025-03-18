//
// Created by stefa on 3/11/2025.
//

#include "Game.h"
Game* Game::instance = nullptr;

void Game::RenderAll() {
    window.display();
    window.clear();
    for (const auto& [_, gameObject]:gameObjects) {
        gameObject->Render(camera);
    }

}

Game *Game::getInstance() {return instance;}

Game::Game(const sf::VideoMode video_mode, const std::string &Title): title_(Title) ,camera(Camera(window)){

    window.create(video_mode, Title, sf::State::Fullscreen);
    if (instance==nullptr) {
        instance=this;

    }
}

Game::~Game() {
    if (IsRunning()) Exit();
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



