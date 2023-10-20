#ifndef PONG_GAME_FIELD_HPP
#define PONG_GAME_FIELD_HPP
#include "component.hpp"
#include "../constants.hpp"
#include "../game_stats.hpp"
#include "text.hpp"


namespace po {


    class GameField : public po::Component {

        private:
            sf::RectangleShape line;
            po::Text playerPointsText;
            po::Text cpuPointsText;

        public:
            GameField();            
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace po



#endif