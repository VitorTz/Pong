#include "../../include/util/util.hpp"



void og::printVector(const sf::Vector2f& v) {
    std::cout << "Vector2f(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")\n"; 
}


void og::printVector(const sf::Vector2i& v) {
    std::cout << "Vector2i(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")\n"; 
}


void og::printVector(const sf::Vector2u& v) {
    std::cout << "Vector2u(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")\n"; 
}



