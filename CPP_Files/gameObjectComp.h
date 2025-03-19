//
// Created by stefa on 3/19/2025.
//

#ifndef GAMEOBJECTCOMP_H
#define GAMEOBJECTCOMP_H
#include "GameObject.h"


class gameObjectComp {
    bool operator() (const GameObject *lhs, const GameObject *rhs) const;
};



#endif //GAMEOBJECTCOMP_H
