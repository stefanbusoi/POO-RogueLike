//
// Created by stefa on 3/12/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <ostream>

#include "GameObject.hpp"
#include "IRenderable.hpp"


class Player :public GameObject,public IRenderable{
    void update(float deltaT) override;
    void Render() override;

public:
    ~Player() override;

    Player(const Player &other)
        : GameObject(other),
          IRenderable(other) {
    }

    Player(Player &&other) noexcept
        : GameObject(std::move(other)),
          IRenderable(std::move(other)) {
    }

    Player & operator=(const Player &other) {
        if (this == &other)
            return *this;
        GameObject::operator =(other);
        IRenderable::operator =(other);
        return *this;
    }

    Player & operator=(Player &&other) noexcept {
        if (this == &other)
            return *this;
        GameObject::operator =(std::move(other));
        IRenderable::operator =(std::move(other));
        return *this;
    }

private:
    friend std::ostream & operator<<(std::ostream &os, const Player &obj);

public:
    Player( const std::string &name="NONNAME", const sf::Transform &transform=sf::Transform::Identity);
    Player(GameObject &parent, const std::string &name="NONNAME", const sf::Transform &transform=sf::Transform::Identity);
    Player()=delete;
};


#endif //PLAYER_H
