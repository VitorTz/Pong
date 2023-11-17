#ifndef OUGI_CAMERA_HPP
#define OUGI_CAMERA_HPP
#include "../ecs/ecs.hpp"
#include <map>
#include <vector>


namespace og {

    class Camera {

        private:
            std::map<std::size_t, std::vector<og::GameObj*>> gameObjs;
        
        public:
            Camera();
            ~Camera();
            void add(og::GameObj* gameObj);
            void rmv(og::GameObj* gameObj);
            void updateZindex(og::GameObj* gameObj, const std::size_t zIndex);
            void draw(sf::RenderWindow& window);

    };
    
} // namespace og



#endif