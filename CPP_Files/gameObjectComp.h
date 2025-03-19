//
// Created by stefa on 3/19/2025.
//

#ifndef GAMEOBJECTCOMP_H
#define GAMEOBJECTCOMP_H
#include <iostream>

#include "GameObject.h"

class GameObject;
class gameObjectComp {
public:
    bool operator()(const GameObject *lhs, const GameObject *rhs) const {
        if (lhs->getUpdateOrder()==rhs->getUpdateOrder()) {
            return lhs->GetId() < rhs->GetId();
        }
        return lhs->getUpdateOrder()<rhs->getUpdateOrder();
    }
};
class IRendableComp {
public:
    bool operator()( IRenderable *lhs,  IRenderable *rhs) const {
        if (lhs->getRenderOrder()==rhs->getRenderOrder()) {
            return dynamic_cast<GameObject*>(lhs)->GetId()<dynamic_cast<GameObject*>(rhs)->GetId();
        }
        return lhs->getRenderOrder()<rhs->getRenderOrder();
    }
};



#endif //GAMEOBJECTCOMP_H
