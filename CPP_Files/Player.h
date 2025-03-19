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

};


#endif //PLAYER_H
