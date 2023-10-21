#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP
#include <random>
#include "component.hpp"
#include "../constants.hpp"
#include "../game_stats.hpp"
#include "../util.hpp"
#include "player.hpp"


namespace po {

    class Ball : public po::Component {

        private:
            sf::CircleShape ballShape;
            sf::Vector2f position;
            sf::Vector2f direction;
            po::Player* players[2];
            po::Player* lastPlayerCollided;
            void move(double dt);
            void handleCollide();
            bool collidePlayer(po::Player* player);

        public:
            Ball(po::Player* player, po::Player* cpu);
            void resetPos();
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;
            const sf::Vector2f& getDirection();
            const sf::Vector2f& getPosition();
            float center();
        
    };
    
} // namespace po


#endif