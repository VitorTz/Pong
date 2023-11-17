#ifndef OUGI_UTIL_HPP
#define OUGI_UTIL_HPP
#include <SFML/System/Vector2.hpp>
#include <iostream>


namespace og {

    void printVector(const sf::Vector2f& v);
    void printVector(const sf::Vector2i& v);
    void printVector(const sf::Vector2u& v);    
    
} // namespace og


#endif