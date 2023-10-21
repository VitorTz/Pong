#include "../../include/components/menu.hpp"


po::Button::Button(
    const std::string& name,
    const std::string& txt,
    std::function<void()> func
) : po::Component(name), isSelected(false), func(func){
    this->bg1.setFillColor(po::primaryColor);
    this->bg1.setSize({po::buttonDimension.x + 4, po::buttonDimension.y + 4});
    this->bg.setFillColor(po::grey);
    this->bg.setSize(po::buttonDimension);
    this->font.loadFromFile(po::fontPath);
    this->text.setCharacterSize(16);
    this->text.setFont(this->font);
    this->text.setFillColor(po::primaryColor);
    this->text.setString(txt);
}


sf::Vector2f& po::Button::getPosition() {
    return this->position;
}


void po::Button::setPosition(const sf::Vector2f& v) {
    this->position.x = v.x;
    this->position.y = v.y;
    this->bg.setPosition(this->position);
    this->bg1.setPosition({this->position.x - 2, this->position.y - 2});
    sf::FloatRect textSize = this->text.getLocalBounds();
    this->text.setPosition(
        {
            (this->position.x + po::buttonDimension.x / 2) - textSize.width / 2,
            (this->position.y + po::buttonDimension.y / 2) - textSize.height / 2 - 5
        }
    );
}


void po::Button::update(double dt) {
    if (this->isSelected && sf::Keyboard::isKeyPressed(po::selectKey)) {
        this->func();
    }
}


void po::Button::setStatus(bool status) {
    this->isSelected = status;
    if (status) {
        this->bg.setFillColor(po::grey1);
    } else {
        this->bg.setFillColor(po::grey);
    }
}


void po::Button::draw(sf::RenderWindow& window) {
    window.draw(this->bg1);
    window.draw(this->bg);
    window.draw(this->text);
}


po::Menu::Menu(std::function<void()> restartLevel) : po::Component("Menu"), _isOpen(false), selectedBtn(0), timer(0.2) {
    this->addBtn("ResumeBtn", "Resume", [this](){this->resume();});
    this->addBtn("RestartBtn", "Restart", restartLevel);
    this->addBtn("QuitBtn", "Quit", [this](){this->quitGame();});
    this->buttons[this->selectedBtn]->setStatus(true);
}


po::Menu::~Menu() {
    for (po::Button* btn : this->buttons) {
        delete btn;
    }
}


void po::Menu::changeSelectedButton(int delta) {
    this->buttons[this->selectedBtn]->setStatus(false);
    this->selectedBtn = (this->selectedBtn + delta) % this->buttons.size();
    this->buttons[this->selectedBtn]->setStatus(true);
}


void po::Menu::updateMenuPos() {
    sf::Vector2f pos(po::screenCenter.x - po::buttonDimension.x / 2, 270);
    for (po::Button* btn : this->buttons) {
        btn->setPosition(pos);
        pos.y += po::buttonDimension.y + po::gapBeetwenButtons;
    }
}


void po::Menu::addBtn(
    const std::string& name, 
    const std::string& txt,
    std::function<void()> func
) {
    po::Button* btn = new po::Button(name, txt, func);
    this->buttons.push_back(btn);
    this->updateMenuPos();
}


void po::Menu::update(double dt) {
    if (this->_isOpen) {
        if (sf::Keyboard::isKeyPressed(po::upKey) && this->timer.check()) {
            this->changeSelectedButton(-1);
        } else if (sf::Keyboard::isKeyPressed(po::downKey) && this->timer.check()) {
            this->changeSelectedButton(1);
        }
        for (po::Button* btn : this->buttons) {
            btn->update(dt);
        }
    } else if (sf::Keyboard::isKeyPressed(po::menuKey)) {
        this->_isOpen = true;
    }
    
}


void po::Menu::draw(sf::RenderWindow& window) {
    if (this->_isOpen)
        for (po::Button* btn : this->buttons)
            btn->draw(window);
}


bool po::Menu::isOpen() {
    return this->_isOpen;
}


void po::Menu::closeMenu() {
    this->_isOpen = false;
}


void po::Menu::resume() {
    this->closeMenu();
}


void po::Menu::quitGame() {
    po::gameStats->exitGame();
}