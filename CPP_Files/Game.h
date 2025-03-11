#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Game {
    sf::RenderWindow window;
    sf::Clock clock;
    std::string title_;
    void RenderAll() {
        window.clear();
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
    void Exit();
    void ProcessGameFrame();

};
