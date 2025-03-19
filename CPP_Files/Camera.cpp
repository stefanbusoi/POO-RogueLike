//
// Created by stefa on 3/10/2025.
//

#include "Camera.h"
#include "Game.h"

Camera::Camera():m_window(&Game::getInstance()->getWindow()) {
        for (const auto& player:Game::getInstance()->getChildrens()) {
                m_player=dynamic_cast<Player*>(player);
                if (m_player!=nullptr)
                        break;
        }
        m_updateOrder=UpdateOrder::Camera;
}

sf::Transform& Camera::getTransform(){
        return m_transform;
}
void Camera::update(float deltaT) {
        m_transform=m_player->getGlobalTransform();
        std::cout<<"Test";
}

void Camera::draw(const sf::Drawable& drawable,sf::Transform transform) const {
        sf::Transform tr=m_transform;
        tr.translate({m_window->getSize().x/-2.0f,m_window->getSize().y/-2.0f});
        m_window->draw(drawable,tr.getInverse()*transform);
}
