#include "../include/util.hpp"


sf::Vector2f po::normalizeVector2(sf::Vector2f& v) {
    sf::Vector2f r(v);
    float magnitude = std::sqrt(v.x * v.x + v.y * v.y);
    if (magnitude > 1) {
        r.x /= magnitude;
        r.y /= magnitude;
    }
    return r;
}


bool po::isInsideScreen(const sf::Vector2f& dimension, const sf::Vector2f& pos) {
    return (
        pos.x >= 0 &&
        pos.x + dimension.x <= po::screenWidth &&
        pos.y >= 0 &&
        pos.y + dimension.y <= po::screenHeight
    );
}



bool po::isInsideScreen(const float radius, const sf::Vector2f& pos) {    
    float dx = std::abs(pos.x - po::screenCenter.x);
    float dy = std::abs(pos.y - po::screenCenter.y);
    
    if (dx > (po::screenCenter.x + radius) || dy > (po::screenCenter.y + radius)) {
        return false;
    }

    if (dx <= (po::screenCenter.x) || dy <= (po::screenCenter.y)) {
        return true;
    }
    
    float cornerDistance = (dx - po::screenCenter.x) * (dx - po::screenCenter.x) + (dy - po::screenCenter.y) * (dy - po::screenCenter.y);
    return cornerDistance <= (radius * radius);
}


int po::genRandomInt(int start, int end) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    return dist(rng);
}