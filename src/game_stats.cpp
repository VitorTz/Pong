#include "../include/game_stats.hpp"
#include <iostream>


po::GameStats* po::GameStats::instance = nullptr;

po::GameStats* po::GameStats::getInstance() {
    if (!instance) {
        instance = new po::GameStats();
    }
    return instance;
}


po::GameStats* po::gameStats = po::GameStats::getInstance();


po::GameStats::GameStats() : timeElapsed(0.0), gameIsRunning(true) {
    this->resetPoints();
}


po::GameStats::~GameStats() {

}


void po::GameStats::resetPoints() {
    this->playerSpeed = po::playerInitialSpeed;
    this->ballSpeed = po::ballInitialSpeed;
    this->playerPoints = 0;
    this->cpuPoints = 0;
}




void po::GameStats::speedUpGame() {
    this->playerSpeed += po::playerSpeedUpdateRate;
    this->ballSpeed += po::playerSpeedUpdateRate;
    
    if (this->playerSpeed > po::maxSpeed) {
        this->playerSpeed = po::maxSpeed;
    }
    if (this->ballSpeed > po::maxSpeed) {
        this->ballSpeed = po::maxSpeed;
    }
}


void po::GameStats::addPointToPlayer() {
    this->playerPoints += 1;
}


void po::GameStats::addPointToCpu() {
    this->cpuPoints += 1;
}


void po::GameStats::updateTimeElapsed(double dt) {
    this->timeElapsed += dt;
}


int po::GameStats::getPlayerSpeed() {
    return this->playerSpeed;
}


int po::GameStats::getBallSpeed() {
    return this->ballSpeed;
}


int po::GameStats::getPlayerPoints() {
    return this->playerPoints;
}


int po::GameStats::getCpuPoints() {
    return this->cpuPoints;
}


double po::GameStats::getTimeElapsed() {
    return this->timeElapsed;
}


void po::GameStats::exitGame() {
    this->gameIsRunning = false;
}


bool po::GameStats::isGameRunning() {
    return this->gameIsRunning;
}