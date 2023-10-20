#include "../include/window.hpp"


po::Window::Window()
: window(
    sf::VideoMode(po::screen_width, po::screen_height),
    po::screen_title,
    sf::Style::Close | sf::Style::Titlebar
),
 changeScene(
    [this](po::SceneId sceneId) {
        if (this->scene->getSceneId() == sceneId) {
            return;
        }
        delete this->scene; this->scene = nullptr;
        switch (sceneId) {
            case po::SceneId::Level:
                this->scene = new po::Level(this->changeScene);
                break;
            case po::SceneId::Menu:
                this->scene = new po::Menu(this->changeScene);
                break;
            default:
                break;
        }
    }
 )
{
    this->window.setFramerateLimit(po::fps);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - po::screen_width / 2,
            desktop.height / 2 - po::screen_height / 2
        )
    );
    this->scene = new po::Level(this->changeScene);
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
    this->scene->update(dt);
}


void po::Window::render() {
    this->window.clear(po::windowBgColor);
    this->scene->render(this->window);
    this->window.display();
}

void po::Window::run() {
    while (this->window.isOpen()) {
        this->handleInput();
        this->update();
        this->render();
    }
}