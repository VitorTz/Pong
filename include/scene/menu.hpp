#ifndef PONG_MENU_HPP
#define PONG_MENU_HPP
#include "scene.hpp"


namespace po {

    class Menu : public po::Scene {


        public:
            Menu(std::function<void(po::SceneId)>& changeScene);

    };
    
} // namespace po


#endif