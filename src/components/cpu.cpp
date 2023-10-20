#include "../../include/components/cpu.hpp"





po::Cpu::Cpu() : po::Player("Cpu") {
    this->pos.x = po::screen_width - po::playerDimension.x;
}


void po::Cpu::updateDirection() {
    this->direction = 0;
}


void po::Cpu::update(double dt) {
    po::Player::update(dt);
}