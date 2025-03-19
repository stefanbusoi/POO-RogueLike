//
// Created by stefa on 3/16/2025.
//

#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "GameObject.h"
#include "IRenderable.h"


class GameMap:public GameObject,public IRenderable{
public:
    void Render() override;

    ~GameMap() override;

    void update(float deltaT) override;

};



#endif //GAMEMAP_H
