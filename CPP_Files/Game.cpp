//
// Created by stefa on 3/11/2025.
//

#include "Game.hpp"

#include "GameMap.hpp"
#include "Player.hpp"


Game* Game::instance = nullptr;

void Game::RenderAll() {
    window.display();
    window.clear();
    for (const auto& gameObject:m_renderableObjects) {
         gameObject->Render();
    }

}


Game *Game::getInstance() {return instance;}

Game::Game(const sf::VideoMode video_mode, const std::string &Title): title_(Title){
    if (instance==nullptr) {
        instance=this;

    }
    window.create(video_mode, Title, sf::State::Fullscreen);
    AddGameObject<Player>();
    camera=AddGameObject<Camera>();
    AddGameObject<GameMap>();
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
    for (const auto& gameObject:gameObjects) {
        gameObject->update(deltaTime.asSeconds());
    }
    RenderAll();
    return  deltaTime.asSeconds();

}



