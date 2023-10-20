#include "../../include/scene/level.hpp"



po::Level::Level(
    std::function<void(po::SceneId)>& changeScene
) : po::Scene(po::SceneId::Level, changeScene) {
    this->addComponent(new po::Player());
    this->addComponent(new po::GameField());
    this->addComponent(new po::Cpu());
}


void po::Level::update(double dt) {
    po::Scene::update(dt);
}