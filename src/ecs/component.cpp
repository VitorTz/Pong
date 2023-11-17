#include "../../include/ecs/ecs.hpp"



og::Component::Component(
    const std::string& name
) : name(name), gameObj(nullptr) {

}


og::Component::~Component() {

}


void og::Component::update(const double dt) {

}


void og::Component::draw(sf::RenderWindow& window) {

}


void og::Component::setGameObj(og::GameObj* gameObj) {
    this->gameObj = gameObj;
}


const std::string& og::Component::getName() {
    return this->name;
}