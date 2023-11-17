#include "../../include/window/mouse.hpp"


og::Mouse* og::Mouse::instance = nullptr;


og::Mouse* og::Mouse::getInstance() {
    if (!instance) {
        instance = new og::Mouse();
    }
    return instance;
}


og::Mouse::Mouse(

) : mousePressed(false),
    mouseDragged(false),
    buttons(
        {
            {sf::Mouse::Left, false},
            {sf::Mouse::Right, false},
            {sf::Mouse::Middle, false},
            {sf::Mouse::XButton1, false},
            {sf::Mouse::XButton2, false},
            {sf::Mouse::ButtonCount, false}
        }
    )  {
    
}


og::Mouse::~Mouse() {

}



void og::Mouse::update(sf::RenderWindow& window) {
    for (auto& pair : this->buttons) {
        pair.second = sf::Mouse::isButtonPressed(pair.first);
    }
    
    const sf::Vector2i currentPos = sf::Mouse::getPosition(window);
    const float deltaX = currentPos.x - this->mousePos.x;
    const float deltaY = currentPos.y - this->mousePos.y;
    const bool mouseIsMoving = deltaX != 0 || deltaY != 0;
    this->mousePos = (sf::Vector2f) currentPos;

    this->mouseDelta.x += deltaX;
    this->mouseDelta.y += deltaY;
    const bool mouseLeftPressed = this->buttons.at(sf::Mouse::Left);
    if (mouseLeftPressed && mouseIsMoving) {
        this->mouseDragged = true;
    } else if (!mouseLeftPressed) {
        this->mouseDragged = false;
        this->mouseDelta.x = 0;
        this->mouseDelta.y = 0;
    }
}


const sf::Vector2f& og::Mouse::getMousePos() {
    return this->mousePos;
}


const sf::Vector2f& og::Mouse::getMouseDelta() {
    return this->mouseDelta;
}


bool og::Mouse::buttonStatus(const sf::Mouse::Button& mouseButton) {
    return this->buttons.at(mouseButton);
}


bool og::Mouse::isMouseDragged() {
    return this->mouseDragged;
}