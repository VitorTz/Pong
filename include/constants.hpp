#ifndef OUGI_CONSTANTS_HPP
#define OUGI_CONSTANTS_HPP
#include <SFML/System/Vector2.hpp>
#include <map>
#include <string>
#include "color.hpp"


namespace og {

    // screen
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGHT = 620;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const sf::Color SCREEN_COLOR = og::Color::Black;
    const std::string SCREEN_TITLE = "Pong";
    const std::string SCREEN_ICON = "res/icon/icon.png";
    const int FPS = 60;
    
    // keyboard
    const int KEYBOARD_STRING_VALUE_MAX_LENGTH = 256;

    // Player
    const sf::Color PLAYER_COLOR = og::Color::White;
    const double PLAYER_SPEED = 250;
    const sf::Vector2f PLAYER_DIMENSION(30, 120);
    const sf::Vector2f PLAYER_POS(
        og::SCREEN_WIDTH - og::PLAYER_DIMENSION.x,
        og::SCREEN_HEIGHT / 2 - og::PLAYER_DIMENSION.y / 2
    );


    namespace Keys {
        
        const sf::Keyboard::Key UP = sf::Keyboard::Key::Up;
        const sf::Keyboard::Key DOWN = sf::Keyboard::Key::Down;

    } // namespace Keys



    

} // namespace og



#endif