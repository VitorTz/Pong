#include "../../include/components/player.hpp"


po::Player::Player() : po::Player("Player") {

}


po::Player::Player(std::string name) : po::Component(name), direction(0.) {
    this->playerBody.setFillColor(po::playerColor);
    this->playerBody.setSize(po::playerDimension);
    this->pos.y = po::screen_height / 2 - po::playerDimension.y / 2;
}


void po::Player::updateDirection() {
    if (sf::Keyboard::isKeyPressed(po::upKey)) {
        this->direction = -1.;
    } else if (sf::Keyboard::isKeyPressed(po::downKey)) {
        this->direction = 1.;
    }
}


bool po::Player::isInsideScreen() {
    return this->pos.y >= 0 && this->pos.y + po::playerDimension.y <= po::screen_height;
}


void po::Player::move(double dt) {
    float deltaY = this->direction * dt * po::playerSpeed;
    this->pos.y += deltaY;
    if (!this->isInsideScreen()) {
        this->pos.y -= deltaY;
    }
    this->playerBody.setPosition(this->pos);
}

void po::Player::update(double dt) {
    this->updateDirection();
    this->move(dt);
}


void po::Player::draw(sf::RenderWindow& window) {
    window.draw(this->playerBody);
}


bool po::Player::collideBall(float radius, const sf::Vector2f& ballPos) {
    sf::Vector2f playerSize = this->playerBody.getSize();
    
    // Calcule o ponto central do retângulo
    sf::Vector2f playerCenter(this->pos.x + playerSize.x / 2, this->pos.y + playerSize.y / 2);

    // Calcule a distância entre o centro do círculo e o centro do retângulo
    float dx = std::abs(ballPos.x - playerCenter.x);
    float dy = std::abs(ballPos.y - playerCenter.y);

    // Verifique se o círculo está mais afastado do retângulo do que a metade de suas dimensões somadas ao raio do círculo
    if (dx > (playerSize.x / 2 + radius) || dy > (playerSize.y / 2 + radius)) {
        return false; // Não há colisão
    }

    // Verifique se o círculo está mais próximo do retângulo do que a metade de suas dimensões
    if (dx <= (playerSize.x / 2) || dy <= (playerSize.y / 2)) {
        return true; // Há colisão
    }

    // Verifique a colisão nos cantos do retângulo
    float cornerDistance = (dx - playerSize.x / 2) * (dx - playerSize.x / 2) + (dy - playerSize.y / 2) * (dy - playerSize.y / 2);
    return cornerDistance <= (radius * radius);
}