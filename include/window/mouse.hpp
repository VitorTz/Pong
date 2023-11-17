#ifndef OUGI_MOUSE_HPP
#define OUGI_MOUSE_HPP
#include <SFML/Graphics.hpp>
#include <map>


namespace og {


    class Mouse {

        private:
            static Mouse* instance;
            Mouse();
        
        public:
            static Mouse* getInstance();
            ~Mouse();
        
        private:
            bool mousePressed;
            bool mouseDragged;
            sf::Vector2f mousePos;
            sf::Vector2f mouseDelta;
            std::map<sf::Mouse::Button, bool> buttons;

        public:
            void update(sf::RenderWindow& window);        

        public:
            const sf::Vector2f& getMousePos();
            const sf::Vector2f& getMouseDelta();
            bool buttonStatus(const sf::Mouse::Button& mouseButton);
            bool isMouseDragged();

    };

    
} // namespace og


#endif
