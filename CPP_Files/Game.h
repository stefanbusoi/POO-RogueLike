//
// Created by stefa on 3/11/2025.
//

#ifndef GAME_H
#define GAME_H
#include "Camera.h"
#include "SFML/Window/Window.hpp"


class Game {
    sf::RenderWindow window;
public:
    bool IsRunning() {
        return window.isOpen();
    }

};



#endif //GAME_H
