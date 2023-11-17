#include "../../include/scene/scene.hpp"



og::Scene::Scene(
    const og::SceneId& sceneId,
    const std::function<void(const og::SceneId&)> changeScene
) : sceneId(sceneId), changeScene(changeScene) {

}



og::Scene::~Scene() {
    for (auto& pair : this->gameObjs) {
        std::cout << "Deleting GameObj " << pair.second->getName() << '\n';
        delete pair.second;
    }
    this->gameObjs.clear();
}


void og::Scene::addGameObj(og::GameObj* gameObj) {
    this->gameObjs.insert({gameObj->getName(), gameObj});
    this->camera.add(gameObj);
}


void og::Scene::rmvGameObj(const std::string& name) {
    try {
        og::GameObj* g = this->gameObjs.at(name);
        this->camera.rmv(g);
        this->gameObjs.erase(name);
        delete g;
    } catch(const std::out_of_range& e) {
        return;
    }
    
}


og::GameObj* og::Scene::getGameObj(const std::string& name) {
    try {
        return this->gameObjs.at(name);
    } catch(const std::out_of_range& e) {
        return nullptr;
    }
    
}


void og::Scene::update(const double dt) {
    for (auto& pair : this->gameObjs) {
        pair.second->update(dt);
    }
}


void og::Scene::draw(sf::RenderWindow& window) {
    this->camera.draw(window);   
}


const og::SceneId& og::Scene::getSceneId() {
    return this->sceneId;
}