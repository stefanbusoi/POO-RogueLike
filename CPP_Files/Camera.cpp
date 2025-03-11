//
// Created by stefa on 3/10/2025.
//

#include "Camera.h"

sf::Transform& Camera::getTransform(){
        return m_transform;
}


void Camera::draw(const sf::Drawable& drawable,sf::Transform transform) const {
        m_window.draw(drawable,m_transform.getInverse()*transform);
}

