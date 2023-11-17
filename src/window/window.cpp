#include "../../include/window/window.hpp"


og::Window* og::Window::instance = nullptr;


og::Window* og::Window::getInstance() {
    if (!instance) 
        instance = new og::Window();
    return instance;
}


og::Window::Window(

) : window(
    sf::VideoMode(og::SCREEN_WIDTH, og::SCREEN_HEIGHT),
    og::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    this->setUpWindow();  
    this->changeScene = [this](const og::SceneId& sceneId) {
        if (this->scene == nullptr || this->scene->getSceneId() != sceneId) {
            if (this->scene) delete this->scene;
            switch (sceneId) {
                case og::SceneId::Level:
                    this->scene = new og::Level(this->changeScene);
                    break;    
                default:
                    break;
            }
        }
    };    
    og::initGlobals();
    this->changeScene(og::firstScene);

}


og::Window::~Window() {
    delete this->scene;
    og::deleteGlobals();
}


void og::Window::setUpWindow() {
    // window fps and position
    this->window.setFramerateLimit(og::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - og::SCREEN_WIDTH / 2,
            desktop.height / 2 - og::SCREEN_HEIGHT / 2
        )
    );  
    // window icon
    sf::Image icon;
    if (!icon.loadFromFile(og::SCREEN_ICON)) {
        this->window.close();
        std::cerr << "Image icon not founded!\n";
        return;
    }
    sf::Vector2u iconSize = icon.getSize();
    this->window.setIcon( 
        iconSize.x, iconSize.y, icon.getPixelsPtr()
    );
}


void og::Window::handleInput() {
    sf::Event e;
    while (this->window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                this->window.close();
                break;
            case sf::Event::KeyPressed:
                og::keyboard->pressKey(e.key);
                break;
            case sf::Event::KeyReleased:
                og::keyboard->releaseKey(e.key);
                break;
            case sf::Event::TextEntered:
                og::keyboard->textEntered(e.text);
                break;
            default:
                break;
        }
    }
}


void og::Window::update() {
    const double dt = this->clock.restart().asSeconds();
    og::currentTime += dt;
    og::mouse->update(this->window);
    this->scene->update(dt);
}


void og::Window::draw() {
    this->window.clear(og::SCREEN_COLOR);
    this->scene->draw(this->window);
    this->window.display();
}


void og::Window::run() {
    while (this->window.isOpen()) {
        this->handleInput();
        this->update();
        this->draw();
    }
}
