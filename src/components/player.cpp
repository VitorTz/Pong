#include "../../include/components/player.hpp"


po::Player::Player() : po::Player("Player") {

}


po::Player::Player(std::string name) : po::Component(name), direction(0.) {
    this->playerBody.setFillColor(po::primaryColor);
    this->playerBody.setSize(po::playerDimension);
    this->resetPos();
}


void po::Player::resetPos() {
    this->pos.x = 0;
    this->pos.y = po::screenHeight / 2 - po::playerDimension.y / 2;
}


void po::Player::updateDirection() {
    this->direction = 0;
    if (sf::Keyboard::isKeyPressed(po::upKey)) {
        this->direction = -1.;
    } else if (sf::Keyboard::isKeyPressed(po::downKey)) {
        this->direction = 1.;
    }
}


bool po::Player::isInsideScreen() {
    return this->pos.y >= 0 && this->pos.y + po::playerDimension.y <= po::screenHeight;
}


void po::Player::move(double dt) {
    float deltaY = this->direction * dt * po::gameStats->getPlayerSpeed();
    this->pos.y += deltaY;
    if (!this->isInsideScreen()) {
        this->pos.y -= deltaY;
    }
    this->playerBody.setPosition(this->pos);
}


void po::Player::update(double dt) {
    this->updateDirection();
    this->move(dt);
}


void po::Player::draw(sf::RenderWindow& window) {
    window.draw(this->playerBody);
}


float po::Player::getDirection() {
    return this->direction;
}

const sf::Vector2f& po::Player::getPosition() {
    return this->pos;
}

sf::Vector2f po::Player::getCenter() {
    return {this->pos.x + po::playerDimension.x / 2, this->pos.y + po::playerDimension.y / 2};
}