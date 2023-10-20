#ifndef PONG_CONSTANTS_HPP
#define PONG_CONSTANTS_HPP
#include <SFML/Graphics.hpp>
#include <string>


namespace po {


    const int screen_width = 1280;
    const int screen_height = 720;
    const std::string screen_title = "Pong!";
    const int fps = 120;

    const sf::Color playerColor = sf::Color::White;
    const sf::Color windowBgColor = sf::Color::Black;
    const sf::Vector2f playerDimension(30, 100);

    const sf::Keyboard::Key upKey = sf::Keyboard::Up;
    const sf::Keyboard::Key downKey = sf::Keyboard::Down;

    const sf::Vector2f gameFieldLineDimension(10, 50);
    const int gameFieldLineGap = 20;
    
    const std::string fontPath = "res/font/Roboto-Regular.ttf";

    const sf::Vector2f playerTextPosition(po::screen_width / 2 - 40, 20);
    const sf::Vector2f cpuTextPosition(po::screen_width / 2 + 40, 20);
    const int textSize = 32;

    enum class SceneId {
        Level,
        Menu
    };
    
} // namespace po



#endif