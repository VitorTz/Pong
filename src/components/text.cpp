#include "../../include/components/text.hpp"



po::Text::Text(
    std::string name, 
    std::string text, 
    std::size_t size,
    sf::Vector2f position
) : po::Component(name), 
    textStr(text),
    position(position) {
    this->font.loadFromFile(po::fontPath);
    this->text.setFont(this->font);
    this->text.setFillColor(po::playerColor);
    this->text.setCharacterSize(size);
    this->text.setPosition(position);
    this->changeText(text);
}


std::string& po::Text::getText() {
    return this->textStr;
}


void po::Text::changeText(const std::string& text) {
    this->text.setString(text);
}


void po::Text::update(double dt) {
    return;
}

void po::Text::draw(sf::RenderWindow& window) {
    window.draw(this->text);
}


const sf::Vector2f& po::Text::getPosition() {
    return this->position;
}


void po::Text::setPosition(const sf::Vector2f& position) {
    this->position = position;
    this->text.setPosition(this->position);
}


sf::Vector2f po::Text::getDimension() { 
    sf::FloatRect d = this->text.getLocalBounds();
    return {d.width, d.height};
}