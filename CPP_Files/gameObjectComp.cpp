//
// Created by stefa on 3/19/2025.
//

#include "gameObjectComp.h"

bool gameObjectComp::operator()(const GameObject *lhs, const GameObject *rhs) const {
    if (lhs->getUpdateOrder()==rhs->getUpdateOrder()) {
        return lhs->getUpdateOrder()<rhs->getUpdateOrder();
    }
    return lhs->GetId() < rhs->GetId();
}
