#include "../../include/components/cpu.hpp"


po::Cpu::Cpu() : po::Player("Cpu"), ball(nullptr), timer(0.1) {
    this->resetPos();
}


void po::Cpu::resetPos() {
    po::Player::resetPos();
    this->pos.x = po::screenWidth - po::playerDimension.x;
}


void po::Cpu::updateDirection() {
    if (this->timer.check()) {
        sf::Vector2f ballPos = this->ball->getPosition();
        sf::Vector2f ballDirection = this->ball->getDirection();
        if (ballDirection.x < 0 || ballPos.x <= po::screenCenter.x + 100) {
            this->direction = 0;
            return;
        }        
        const float ballCenter = this->ball->center();
        if (ballCenter < this->pos.y + 10) {
            this->direction = -1;
        } else if (ballCenter > this->pos.y + po::playerDimension.y - 10) {
            this->direction = 1;
        } else {
            this->direction = 0;
        }        
    }
}


void po::Cpu::update(double dt) {
    po::Player::update(dt);
}


void po::Cpu::setGameBall(po::Ball* ball) {
    this->ball = ball;
}
