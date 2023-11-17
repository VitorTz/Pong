#ifndef OUGI_ECS_HPP
#define OUGI_ECS_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>
#include "../util/transform.hpp"
#include "../constants.hpp"
#include "../game_stats.hpp"
#include "../globals.hpp"
#include "../util/asset_pool.hpp"
#include "../util/util.hpp"


namespace og {


    class Component;


    class GameObj {

        private:
            const std::string name;
            og::Transform transform;
            std::map<std::string, og::Component*> components;

        public:
            GameObj(
                const std::string& name,
                const og::Transform& transform
            );
            GameObj(
                const std::string& name
            );
            ~GameObj();
            void draw(sf::RenderWindow& window);
            void update(const double dt);
            void addComponent(og::Component* component);
            void rmvComponent(const std::string& component);
            og::Component* getComponent(const std::string& componentName);
            og::Transform* getTransform();
            const std::string& getName();
    };


    class Component {
        
        protected:
            const std::string name;
            og::GameObj* gameObj;
        
        public:
            Component(const std::string& name);
            virtual ~Component();
            virtual void update(const double dt);
            virtual void draw(sf::RenderWindow& window);
            virtual void setGameObj(og::GameObj* gameObj);
            const std::string& getName();

    };
    
} // namespace og


#endif