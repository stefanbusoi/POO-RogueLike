//
// Created by stefa on 3/10/2025.
//

#include "Camera.hpp"
#include "Game.hpp"



Camera::Camera(GameObject &parent, const std::string &name, const sf::Transform &transform):m_window(&Game::getInstance()->getWindow()) {
        for (const auto& player:Game::getInstance()->getChildrens()) {
                m_player=dynamic_cast<Player*>(player);
                if (m_player!=nullptr)
                        break;
        }
        m_parent=&parent;
        m_name=name;
        m_transform=transform;
        m_updateOrder=UpdateOrder::Camera;
}

sf::Transform& Camera::getTransform(){
        return m_transform;
}
void Camera::update([[maybe_unused]]float deltaT) {

        m_transform=m_player->getGlobalTransform();
}

void Camera::draw(const sf::Drawable& drawable, const sf::Transform &transform) const {
        sf::Transform tr=m_transform;
        tr.translate({m_window->getSize().x/-2.0f,m_window->getSize().y/-2.0f});
        m_window->draw(drawable,tr.getInverse()*transform);
}
