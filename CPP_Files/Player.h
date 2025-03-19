//
// Created by stefa on 3/12/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "IRenderable.h"


class Player :public GameObject,public IRenderable{
    void update(float deltaT) override;
    ~Player() override;
    void Render() override;

public:
    explicit Player(GameObject &parent)
        : GameObject(parent) {
        m_renderOrder=RenderOrder::Player;
        m_updateOrder=UpdateOrder::Default;
    }
    Player(GameObject &parent, const std::string &name, const sf::Transform &transform)
        : GameObject(parent, name, transform) {
        m_renderOrder=RenderOrder::Player;
        m_updateOrder=UpdateOrder::Default;
    }

    Player(){
        m_renderOrder=RenderOrder::Player;
        m_updateOrder=UpdateOrder::Default;
    }
};


#endif //PLAYER_H
