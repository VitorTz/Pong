#ifndef PONG_CONSTANTS_HPP
#define PONG_CONSTANTS_HPP
#include <SFML/Graphics.hpp>
#include <string>


namespace po {


    // window
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const sf::Vector2f screenSize(screenWidth, screenHeight);
    const std::string screenTitle = "Pong!";
    const sf::Vector2f screenCenter(screenWidth / 2, screenHeight / 2);
    const int screenFps = 120;

    // colors 
    const sf::Color primaryColor = sf::Color::White;
    const sf::Color secondaryColor = sf::Color::Black;
    const sf::Color grey(41, 42, 51);
    const sf::Color grey1(79, 78, 79);
    const sf::Color windowBgColor = sf::Color::Black;

    // dimensions
    const sf::Vector2f playerDimension(30, 100);
    const float ballRadius = 10.f;

    // keys
    const sf::Keyboard::Key upKey = sf::Keyboard::Up;
    const sf::Keyboard::Key downKey = sf::Keyboard::Down;
    const sf::Keyboard::Key selectKey = sf::Keyboard::Space;
    const sf::Keyboard::Key menuKey = sf::Keyboard::Escape;

    // GameField
    const sf::Vector2f gameFieldLineDimension(10, 50);
    const int gameFieldGapBeetwenLines = 20;
    const sf::Vector2f gameFieldPlayerPointsPos(po::screenWidth / 2 - 40, 20);
    const sf::Vector2f gameFieldCpuPointsPos(po::screenWidth / 2 + 40, 20);
    
    const int gameFieldTxtSize = 32;
    const int maxSpeed = 600;
    const double speedIncreaseUpdateRate = 0.5;
    
    const int playerSpeedUpdateRate = 7;
    const int playerInitialSpeed = 300;
    const int ballInitialSpeed = 350;

    // buttons
    const sf::Vector2f buttonDimension(150, 40);
    const int gapBeetwenButtons = 20;
    
    // resources
    const std::string fontPath = "res/font/Roboto-Regular.ttf";

    // enum
    enum class SceneId {
        Level,
        Menu
    };
    
} // namespace po



#endif