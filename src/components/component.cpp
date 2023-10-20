#include "../../include/components/component.hpp"


po::Component::Component(std::string name) : name(name) {

}

po::Component::~Component() {

}

std::string& po::Component::getName() {
    return this->name;
}