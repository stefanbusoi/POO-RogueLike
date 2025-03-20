//
// Created by stefa on 3/12/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.hpp"
#include "IRenderable.hpp"


class Player :public GameObject,public IRenderable{
    void update(float deltaT) override;
    ~Player() override;
    void Render() override;

public:
    Player(GameObject &parent, const std::string &name="NONNAME", const sf::Transform &transform=sf::Transform::Identity);
    Player()=delete;
};


#endif //PLAYER_H
