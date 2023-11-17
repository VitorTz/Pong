#ifndef OUGI_SCENE_HPP
#define OUGI_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <string>
#include "../constants.hpp"
#include "../globals.hpp"
#include "../game_stats.hpp"
#include "../window/camera.hpp"
#include "../ecs/ecs.hpp"
#include "../ecs/components/components.hpp"
#include "../util/util.hpp"


namespace og {

    enum class SceneId {
        Level
    };

    const og::SceneId firstScene = og::SceneId::Level;


    class Scene {

        protected:
            const og::SceneId sceneId;
            const std::function<void(const og::SceneId&)> changeScene;
            std::map<std::string, og::GameObj*> gameObjs;
            og::Camera camera;
        
        protected:
            void addGameObj(og::GameObj* gameObj);
            void rmvGameObj(const std::string& name);
            og::GameObj* getGameObj(const std::string& name);

        public:
            Scene(
                const og::SceneId& sceneId,
                const std::function<void(const og::SceneId&)> changeScene
            );
            virtual ~Scene();
            virtual void update(const double dt);
            virtual void draw(sf::RenderWindow& window);            
            const og::SceneId& getSceneId();

    };
    
} // namespace og


#endif