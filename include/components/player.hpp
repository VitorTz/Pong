#ifndef PONG_PLAYER_HPP
#define PONG_PLAYER_HPP
#include "component.hpp"
#include "../game_stats.hpp"
#include "../constants.hpp"


namespace po {


    class Player : public po::Component {
        
        protected:
            float direction;
            sf::RectangleShape playerBody;
            sf::Vector2f pos;
            bool isInsideScreen();
            virtual void updateDirection();
        
        private:
            void move(double dt);

        public:
            Player();
            Player(std::string name);
            virtual void update(double dt) override;
            virtual void draw(sf::RenderWindow& window) override;
            bool collideBall(float radius, const sf::Vector2f& pos);

    };
    
} // namespace po


#endif