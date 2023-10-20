#ifndef PONG_COMPONENT_HPP
#define PONG_COMPONENT_HPP
#include <SFML/Graphics.hpp>
#include <string>


namespace po {


    class Component {
        
        protected:
            std::string name;

        public:

            Component(std::string name);
            virtual ~Component();
            virtual void update(double dt) = 0;
            virtual void draw(sf::RenderWindow& window) = 0;
            std::string& getName();
    };
    
} // namespace po


#endif
