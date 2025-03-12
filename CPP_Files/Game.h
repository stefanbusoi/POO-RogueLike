#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "GameObject.h"

class Game {
    sf::RenderWindow window;
    sf::Clock clock;
    std::string title_;
    Camera camera;

    //Camera camera;
    void RenderAll() {
        window.clear();
        for (const auto& [i, j]:gameObjects) {
            j->Render(camera);
        }
        window.display();
    }
    std::unordered_map<int,GameObject*> gameObjects;

public:
    static Game* game;

    Game(sf::VideoMode video_mode,std::string Title);
    ~Game(){
        if (IsRunning()) Exit();
    }
    bool IsRunning() const;
    sf::RenderWindow &getWindow() {return window;}
    Camera& getCamera() {return camera;}
    void Exit();
    float ProcessGameFrame();
    template <typename T>
    void AddGameObject();
};

template<typename T>
void Game::AddGameObject() {
    T* newGameObject = new T();
    gameObjects.insert(std::pair<int,GameObject*>(newGameObject->GetId(),newGameObject));
}
