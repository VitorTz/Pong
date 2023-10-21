#ifndef PONG_WINDOW_HPP
#define PONG_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include "scene/scenes.hpp"
#include "game_stats.hpp"


namespace po {
    
    class Window {

        private:
            
            sf::RenderWindow window;
            sf::Clock clock;
            std::function<void(po::SceneId)> changeScene;
            po::Scene* scene;

        public:

            Window();
            ~Window();
            void run();

        private:

            void handleInput();
            void update();
            void render();
            

    };
} // namespace pg


#endif