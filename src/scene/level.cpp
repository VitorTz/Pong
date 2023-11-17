#include "../../include/scene/level.hpp"



og::Level::Level(
    const std::function<void(const og::SceneId&)> changeScene
) : og::Scene(og::SceneId::Level, changeScene) {
    og::GameObj* player = new og::GameObj("Player");
    player->addComponent(new og::Player());
    this->addGameObj(player);
}