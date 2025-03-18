#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Camera.h"
class Game :public GameObject{
    sf::RenderWindow window;
    sf::Clock clock;
    std::string title_;
    Camera* camera;
    static Game* instance;
    void RenderAll();
    static Game* game;
    std::map<int,GameObject*> gameObjects;

public:
    static Game *getInstance();
    Game(sf::VideoMode video_mode, const std::string &Title);
    ~Game() override;
    bool IsRunning() const;
    sf::RenderWindow &getWindow() {return window;}
    Camera& getCamera() const {return *camera;}
    std::map<int,GameObject*>& getGameObjects(){return gameObjects;}
    void Exit();
    float ProcessGameFrame();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

};



