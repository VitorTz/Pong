#include "../../include/window/camera.hpp"


og::Camera::Camera() {

}


og::Camera::~Camera() {

}


void og::Camera::add(og::GameObj* gameObj) {
    const std::size_t zIndex = gameObj->getTransform()->zIndex;
    if (this->gameObjs.find(zIndex) == this->gameObjs.end()) {
        this->gameObjs.insert({zIndex, {}});
    }
    this->gameObjs.at(zIndex).push_back(gameObj);
}


void og::Camera::rmv(og::GameObj* gameObj) {
    const std::size_t zIndex = gameObj->getTransform()->zIndex;
    if (this->gameObjs.find(zIndex) != this->gameObjs.end()) {
        std::vector<og::GameObj*>& v = this->gameObjs.at(zIndex);
        for (std::size_t i = 0; i < v.size(); i++) {
            if (v.at(i) == gameObj) {
                v.erase(v.begin() + i);
            }
        }
    }
}


void og::Camera::updateZindex(og::GameObj* gameObj, const std::size_t zIndex) {
    this->rmv(gameObj);
    gameObj->getTransform()->zIndex = zIndex;
    this->add(gameObj);
}


void og::Camera::draw(sf::RenderWindow& window) {
    for (auto& pair : this->gameObjs) {
        for (auto& obj : pair.second) {
            obj->draw(window);
        }
    }
}