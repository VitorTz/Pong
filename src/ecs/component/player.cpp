#include "../../../include/ecs/components/player.hpp"
#include <iostream>


og::Player::Player(
    
) : og::Component("Player") {
    this->playerSprite.setFillColor(og::PLAYER_COLOR);
    this->playerSprite.setSize(og::PLAYER_DIMENSION);
}


og::Player::~Player() {

}


void og::Player::update(const double dt) {
    this->handleMovement(dt);
}


void og::Player::draw(sf::RenderWindow& window) {
    window.draw(this->playerSprite);
}


void og::Player::setGameObj(og::GameObj* gameObj) {
    og::Component::setGameObj(gameObj);
    og::Transform* t = gameObj->getTransform();
    t->dimension = og::PLAYER_DIMENSION;
    t->position = og::PLAYER_POS;
    t->speed = og::PLAYER_SPEED;
}


void og::Player::handleMovement(const double dt) {
    og::Transform* t = this->gameObj->getTransform();
    
    if (sf::Keyboard::isKeyPressed(og::Keys::UP)) {
        t->direction.y = -1;
    } else if (sf::Keyboard::isKeyPressed(og::Keys::DOWN)) {
        t->direction.y = 1;
    }
    t->move(dt);
    if (t->top() < 0) {
        t->setTop(0);
    } else if (t->bottom() > og::SCREEN_HEIGHT) {
        t->setBottom(og::SCREEN_HEIGHT);
    }
    this->playerSprite.setPosition(t->position);
}