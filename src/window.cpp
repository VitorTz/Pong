#include "../include/window.hpp"


po::Window::Window()
: window(
    sf::VideoMode(po::screenWidth, po::screenHeight),
    po::screenTitle,
    sf::Style::Close | sf::Style::Titlebar
) {
    this->window.setFramerateLimit(po::screenFps);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - po::screenWidth / 2,
            desktop.height / 2 - po::screenHeight / 2
        )
    );
    this->scene = new po::Level();
}

po::Window::~Window() {
    delete this->scene;
}


void po::Window::handleInput() {
    sf::Event e;
    while (this->window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                this->window.close();
                break;
            default:
                break;
        }
    }
}


void po::Window::update() {
    double dt = this->clock.restart().asSeconds();
    po::gameStats->updateTimeElapsed(dt);
    this->scene->update(dt);
}


void po::Window::render() {
    this->window.clear(po::windowBgColor);
    this->scene->render(this->window);
    this->window.display();
}

void po::Window::run() {
    while (this->window.isOpen() && po::gameStats->isGameRunning()) {
        this->handleInput();
        this->update();
        this->render();
    }
}