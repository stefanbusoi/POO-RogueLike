//
// Created by stefa on 3/16/2025.
//

#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "GameObject.hpp"
#include "IRenderable.hpp"


class GameMap:public GameObject,public IRenderable{
public:
    void Render() override;
    GameMap(GameObject &parent, const std::string &name="NONNAME", const sf::Transform &transform=sf::Transform::Identity);

    ~GameMap() override;

    void update(float deltaT) override;

};



#endif //GAMEMAP_H
