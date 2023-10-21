#include "../../include/components/game_field.hpp"



po::GameField::GameField() 
:   po::Component("GameField"),
    linePos(po::screenWidth / 2 - po::gameFieldLineDimension.x / 2, po::gameFieldGapBeetwenLines),
    playerPointsText("PlayerPoints", "0", po::gameFieldTxtSize, po::gameFieldPlayerPointsPos),
    cpuPointsText("CpuPoints", "0", po::gameFieldTxtSize, po::gameFieldCpuPointsPos),
    timer(po::speedIncreaseUpdateRate)
 {
    this->line.setFillColor(po::primaryColor);
    this->line.setSize(po::gameFieldLineDimension);
}


void po::GameField::update(double dt) {
    if (this->timer.check()) { po::gameStats->speedUpGame(); }
    this->playerPointsText.changeText(std::to_string(po::gameStats->getPlayerPoints()));
    this->cpuPointsText.changeText(std::to_string(po::gameStats->getCpuPoints()));
    sf::Vector2f d = this->playerPointsText.getDimension();    
    this->playerPointsText.setPosition(
        {po::gameFieldPlayerPointsPos.x - d.x - 5, po::gameFieldPlayerPointsPos.y}
    );
}


void po::GameField::draw(sf::RenderWindow& window) {    
    for (int i = 0; i < 10; i++) {
        this->line.setPosition(this->linePos);
        window.draw(this->line);
        this->linePos.y += po::gameFieldLineDimension.y + po::gameFieldGapBeetwenLines;
    }
    this->linePos.y = po::gameFieldGapBeetwenLines;
    this->playerPointsText.draw(window);
    this->cpuPointsText.draw(window);
}