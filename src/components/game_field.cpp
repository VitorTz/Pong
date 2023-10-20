#include "../../include/components/game_field.hpp"



po::GameField::GameField() 
:   po::Component("GameField"),
    playerPointsText("PlayerPoints", "0", po::textSize, po::playerTextPosition),
    cpuPointsText("CpuPoints", "0", po::textSize, po::cpuTextPosition)
 {
    this->line.setFillColor(po::playerColor);
    this->line.setSize(po::gameFieldLineDimension);
    this->line.setPosition(
        sf::Vector2f(
            po::screen_width / 2 - po::gameFieldLineDimension.x / 2,
            po::gameFieldLineGap
        )
    );
}


void po::GameField::update(double dt) {
    this->playerPointsText.changeText(std::to_string(po::playerPoints));
    this->cpuPointsText.changeText(std::to_string(po::cpuPoints));
    sf::Vector2f d = this->playerPointsText.getDimension();    
    this->playerPointsText.setPosition(
        {po::playerTextPosition.x - d.x - 5, po::playerTextPosition.y}
    );
}


void po::GameField::draw(sf::RenderWindow& window) {    
    sf::Vector2f pos = this->line.getPosition();
    sf::Vector2f d = this->line.getSize();
    const float y = pos.y;
    for (int i = 0; i < 10; i++) {
        window.draw(this->line);
        pos.y += d.y + po::gameFieldLineGap;
        this->line.setPosition(pos);
    }
    pos.y = y;
    line.setPosition(pos);
    this->playerPointsText.draw(window);
    this->cpuPointsText.draw(window);
}