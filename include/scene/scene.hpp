#ifndef PONG_SCENE_HPP
#define PONG_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <functional>
#include <constants.hpp>
#include <map>
#include "../components/components.hpp"


namespace po {

    class Scene {

        protected:
            po::SceneId sceneId;
            std::function<void(po::SceneId)>& changeScene;
            std::map<std::string, po::Component*> components;
        
        public:
            Scene(po::SceneId sceneId, std::function<void(po::SceneId)>& changeScene);
            virtual ~Scene();
            virtual void update(double dt);
            virtual void render(sf::RenderWindow& window);
            void addComponent(po::Component* component);
            void rmvComponent(const std::string& name);
            po::Component* getComponent(const std::string& name);
            po::SceneId& getSceneId();

    };  
    
} // namespace po


#endif