#ifndef PONG_UTIL_HPP
#define PONG_UTIL_HPP
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>
#include "constants.hpp"


namespace po {


    sf::Vector2f normalizeVector2(sf::Vector2f& v);
    bool isInsideScreen(const sf::Vector2f& dimension, const sf::Vector2f& pos);
    bool isInsideScreen(const float radius, const sf::Vector2f& pos);
    int genRandomInt(int start, int end);
    
} // namespace po


#endif