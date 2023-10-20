#ifndef PONG_LEVEL_HPP
#define PONG_LEVEL_HPP
#include "scene.hpp"


namespace po {


    class Level : public po::Scene {

        public:
            Level(std::function<void(po::SceneId)>& changeScene);
            void update(double dt) override;

    };
    
} // namespace po


#endif
