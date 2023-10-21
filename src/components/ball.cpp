#include "../../include/components/ball.hpp"
#include <iostream>



po::Ball::Ball(po::Player* player, po::Player* cpu) 
:   po::Component("Ball"),
    lastPlayerCollided(nullptr) {
    this->ballShape.setRadius(po::ballRadius);
    this->ballShape.setFillColor(po::primaryColor);
    this->players[0] = player;
    this->players[1] = cpu;
    this->resetPos();
}


void po::Ball::move(double dt) {
    int ballSpeed = po::gameStats->getBallSpeed();
    sf::Vector2f d = po::normalizeVector2(this->direction);
    this->position.x += dt * d.x * ballSpeed;
    this->position.y += dt * d.y * ballSpeed;
    this->ballShape.setPosition(this->position);
}


void po::Ball::resetPos() {
    // pos
    this->position.x = po::screenCenter.x;
    this->position.y = po::genRandomInt(po::screenHeight * 0.2, po::screenHeight * 0.8);
    // direction
    int num[2] = {-1, 1};    
    this->direction.x = num[po::genRandomInt(0, 1)] * 3;
    this->direction.y = num[po::genRandomInt(0, 1)];
    // reset collide
    this->lastPlayerCollided = nullptr;
}


bool po::Ball::collidePlayer(po::Player* player) {  
    sf::Vector2f circleCenter(this->position.x + po::ballRadius, this->position.y + po::ballRadius);
    sf::Vector2f playerCenter = player->getCenter();
    
    sf::Vector2f circleDistance(std::abs(circleCenter.x - playerCenter.x), std::abs(circleCenter.y - playerCenter.y));
    
    if (circleDistance.x > (po::playerDimension.x / 2 + po::ballRadius))
        return false;
    if (circleDistance.y > (po::playerDimension.y / 2 + po::ballRadius))
        return false;

    if (circleDistance.x <= (po::playerDimension.x / 2))
        return true;

    if (circleDistance.y <= (po::playerDimension.y / 2))
        return true;

    float cornerDistance_sq = std::pow((circleDistance.x - po::playerDimension.x / 2), 2) + std::pow((circleDistance.y - po::playerDimension.y / 2), 2);

    if (cornerDistance_sq <= (po::ballRadius * po::ballRadius))
        return true;
        
    return false;
}


void po::Ball::handleCollide() {
    for (po::Player* player : this->players) {
        bool collide = this->collidePlayer(player); 
        if (collide && player != this->lastPlayerCollided) {
            this->direction.x = -this->direction.x;
            float playerDirection = player->getDirection();
            if (playerDirection != 0)
                this->direction.y = playerDirection;
            this->lastPlayerCollided = player;
            return;
        }
    }
    if (this->position.x > po::screenWidth) {
        po::gameStats->addPointToPlayer();
        this->resetPos();
    } else if (this->position.x < 0) {
        po::gameStats->addPointToCpu();
        this->resetPos();
    }
    if (this->position.y <= 0 || this->position.y + po::ballRadius * 2 >= po::screenHeight) {
        this->direction.y = -this->direction.y;        
    }
}


void po::Ball::update(double dt) {
    this->move(dt);
    this->handleCollide();
}


void po::Ball::draw(sf::RenderWindow& window) {
    window.draw(this->ballShape);    
}


const sf::Vector2f& po::Ball::getDirection() {
    return this->direction;
}


const sf::Vector2f& po::Ball::getPosition() {
    return this->position;
}


float po::Ball::center() {
    return po::ballRadius + this->position.y;
}