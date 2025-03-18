//
// Created by stefa on 3/11/2025.
//

#include "Game.h"

#include "GameMap.h"
#include "Player.h"


Game* Game::instance = nullptr;

void Game::RenderAll() {
    window.display();
    window.clear();
    for (const auto& [_, gameObject]:m_children) {
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
    for (const auto& [i, j]:m_children) {
        j->update(deltaTime.asSeconds());
    }
    RenderAll();
    return  deltaTime.asSeconds();
}



