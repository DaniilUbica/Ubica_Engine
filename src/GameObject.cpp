#include "../include/Engine/GameObject.h"

sf::Sprite GameObject::getSprite() {
    return sprite;
}

sf::Vector2f GameObject::getPosition() {
    return sf::Vector2f(coordX, coordY);
}

sf::Vector2f GameObject::getSize() {
    return sf::Vector2f(width, height);
}

void GameObject::setPosition(int coordX, int coordY) {
    this->coordX = coordX;
    this->coordY = coordY;
}
