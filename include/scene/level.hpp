#ifndef OUGI_LEVEL_HPP
#define OUGI_LEVEL_HPP
#include "scene.hpp"



namespace og {


    class Level : public og::Scene {

        public:
            Level(
                const std::function<void(const og::SceneId&)> changeScene
            );

    };
    
} // namespace og


#endif