//
// Created by stefa on 3/12/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Window/Keyboard.hpp"


class Player :public GameObject{
    void update(float deltaT) override;
    ~Player() override;
    void Render(const Camera& camera ) override;
};
void start();


#endif //PLAYER_H
