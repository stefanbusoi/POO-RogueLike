//
// Created by stefa on 3/16/2025.
//

#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "GameObject.h"


class GameMap:public GameObject{
public:
    void Render(const Camera &camera) override;

    ~GameMap() override;

    void update(float deltaT) override;

    void start() override;
};



#endif //GAMEMAP_H
