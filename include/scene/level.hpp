#ifndef PONG_LEVEL_HPP
#define PONG_LEVEL_HPP
#include "scene.hpp"


namespace po {


    class Level : public po::Scene {

        private:
            po::Menu* menu;
            void restartLevel();
            
        public:
            Level();            
            void update(double dt) override;

    };
    
} // namespace po


#endif
