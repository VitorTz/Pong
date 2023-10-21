#include "../../include/scene/scene.hpp"


po::Scene::Scene(po::SceneId sceneId) : sceneId(sceneId) {

}


po::Scene::~Scene() {
    for (auto& pair : this->components) {
        delete pair.second;
    }
    this->components.clear();
}


void po::Scene::addComponent(po::Component* component) {
    this->components.insert({component->getName(), component});
}


void po::Scene::rmvComponent(const std::string& name) {
    if (this->components.find(name) != this->components.end()) {
        po::Component* c = this->components.at(name);
        delete c;
        this->components.erase(name);
    }
}


po::Component* po::Scene::getComponent(const std::string& name) {
    if (this->components.find(name) != this->components.end()) {
        return this->components.at(name);
    }
    return nullptr;
}


void po::Scene::update(double dt) {
    for (auto& pair : this->components) {
        pair.second->update(dt);
    }
}

void po::Scene::render(sf::RenderWindow& window) {
    for (auto& pair : this->components) {
        pair.second->draw(window);
    }
}


po::SceneId& po::Scene::getSceneId() {
    return this->sceneId;
}