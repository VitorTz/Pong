#include "../../include/scene/level.hpp"



po::Level::Level() : po::Scene(po::SceneId::Level), menu(nullptr) {
    po::Player* player = new po::Player();
    po::Cpu* cpu = new po::Cpu();
    po::Ball* ball = new po::Ball(player, cpu);
    cpu->setGameBall(ball);
    this->addComponent(player);
    this->addComponent(cpu);
    this->addComponent(new po::GameField());
    this->addComponent(ball);
    this->menu = new po::Menu([this](){this->restartLevel();});
    this->addComponent(this->menu);
}


void po::Level::update(double dt) {
    this->menu->update(dt);
    if (!this->menu->isOpen()) {
        po::Scene::update(dt);        
    }
}


void po::Level::restartLevel() {
    po::gameStats->resetPoints();
    po::Ball* ball = (po::Ball*) this->components.at("Ball");
    ball->resetPos();
    this->menu->closeMenu();
    po::Player* player = (po::Player*) this->components.at("Player");
    po::Cpu* cpu = (po::Cpu*) this->components.at("Cpu");
    player->resetPos();
    cpu->resetPos();
}
