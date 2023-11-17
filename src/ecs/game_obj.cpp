#include "../../include/ecs/ecs.hpp"



og::GameObj::GameObj(
    const std::string& name,
    const og::Transform& transform
) : name(name), transform(transform) {
    
}


og::GameObj::GameObj(
    const std::string& name
) : name(name) {
    
}


og::GameObj::~GameObj() {
    for (auto& pair : this->components) {
        std::cout << "Deleting Component " << pair.second->getName() << '\n';
        delete pair.second;
    }
    this->components.clear();
}


void og::GameObj::update(const double dt) {
    for (auto& pair : this->components) {
        pair.second->update(dt);
    }
}


void og::GameObj::draw(sf::RenderWindow& window) {
    for (auto& pair : this->components) {
        pair.second->draw(window);
    }
}


const std::string& og::GameObj::getName() {
    return this->name;
}


og::Transform* og::GameObj::getTransform() {
    return &this->transform;
}


void og::GameObj::addComponent(og::Component* component) {
    this->components.insert({component->getName(), component});
    component->setGameObj(this);
}


og::Component* og::GameObj::getComponent(const std::string& componentName) {
    try {
        return this->components.at(componentName);
    }
    catch(const std::out_of_range& e) {
        return nullptr;
    }
}


void og::GameObj::rmvComponent(const std::string& componentName) {
    if (this->components.find(componentName) != this->components.end()) {
        og::Component* c = this->components.at(componentName);
        this->components.erase(componentName);
        delete c;
    }
}