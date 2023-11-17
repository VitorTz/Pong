#ifndef PONG_PLAYER_HPP
#define PONG_PLAYER_HPP
#include "../ecs.hpp"
#include "sprite.hpp"


namespace og {

    class Player : public og::Component {
    
        private:
            sf::RectangleShape playerSprite;
            void handleMovement(const double dt);

        public:
            Player();
            ~Player() override;
            void update(const double dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(og::GameObj* gameObj) override;

    };
    
} // namespace og


#endif