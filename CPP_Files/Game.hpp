#pragma once

#include <iostream>
#include <set>

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Camera.hpp"
#include "gameObjectComp.hpp"

class Game :public GameObject{
    sf::RenderWindow window;
    sf::Clock clock;
    std::string title_;
    Camera* camera;
    static Game* instance;
    void RenderAll();
    std::set<GameObject*,gameObjectComp> gameObjects;
    std::set<IRenderable*,iRendableComp> m_renderableObjects;

public:
    static Game *getInstance();
    Game(sf::VideoMode video_mode, const std::string &Title);
    ~Game() override;
    bool IsRunning() const;
    sf::RenderWindow &getWindow() {return window;}
    Camera& getCamera() const {return *camera;}
    std::set<GameObject*,gameObjectComp>& getGameObjects(){return gameObjects;}
    void Exit();
    float ProcessGameFrame();

    std::set<IRenderable*,iRendableComp>& getRenderOrder(){return m_renderableObjects;};

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

};



