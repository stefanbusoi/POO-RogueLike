#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Game :public GameObject{
    sf::RenderWindow window;
    sf::Clock clock;
    std::string title_;
    Camera camera;
    static Game* instance;
    //Camera camera;
    void RenderAll();
    static Game* game;

    std::unordered_map<int,GameObject*> gameObjects;

public:
    static Game *getInstance();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game(sf::VideoMode video_mode,std::string Title);
    ~Game() override;

    bool IsRunning() const;
    sf::RenderWindow &getWindow() {return window;}
    Camera& getCamera() {return camera;}
    void Exit();
    float ProcessGameFrame();
    template <typename T>
    T* AddGameObject();
};

template<typename T>
T* Game::AddGameObject() {
    T* newGameObject = new T();
    gameObjects.insert(std::pair<int,GameObject*>(newGameObject->GetId(),newGameObject));
    return newGameObject;
}
