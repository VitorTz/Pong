#ifndef PONG_TEXT_HPP
#define PONG_TEXT_HPP
#include "component.hpp"
#include "../constants.hpp"


namespace po {


    class Text : public po::Component {

        private:
            std::string textStr;
            sf::Vector2f position;
            sf::Font font;
            sf::Text text;

        public:

            Text(
                std::string name, 
                std::string text, 
                std::size_t size,
                sf::Vector2f position
            );
            void changeText(const std::string& text);
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;
            std::string& getText();
            const sf::Vector2f& getPosition();
            void setPosition(const sf::Vector2f& position);
            sf::Vector2f getDimension();
    };
    
} // namespace po



#endif