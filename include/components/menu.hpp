#ifndef MENU_PONG_HPP
#define MENU_PONG_HPP
#include <vector>
#include <string>
#include <functional>
#include "component.hpp"
#include "../constants.hpp"
#include "../game_stats.hpp"
#include "../timer.hpp"


namespace po {

    class Button : po::Component {

        private:
            sf::Font font;
            sf::Text text;
            sf::RectangleShape bg1;
            sf::RectangleShape bg;
            sf::Vector2f position;
            bool isSelected;
            std::function<void()> func;

        public:

            Button(
                const std::string& name, 
                const std::string& txt,
                std::function<void()> func
            );
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;
            sf::Vector2f& getPosition();
            void setPosition(const sf::Vector2f& v);
            void setStatus(bool status);
    };


    class Menu : public po::Component {

        private:
            sf::RectangleShape bg;
            std::vector<po::Button*> buttons;
            bool _isOpen;
            int selectedBtn;
            po::Timer timer;
            void addBtn(
                const std::string& name, 
                const std::string& txt,
                std::function<void()> func
            );
            void changeSelectedButton(int delta);
            void updateMenuPos();
            void resume();
            void quitGame();

        public:
            Menu(std::function<void()> restartLevel);
            ~Menu();
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;
            bool isOpen();
            void closeMenu();

    };
    
} // namespace po


#endif