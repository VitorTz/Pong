#ifndef OUGI_TRANSFORM_HPP
#define OUGI_TRANSFORM_HPP
#include <SFML/System/Vector2.hpp>
#include <cstdlib>


namespace og {

    class Transform {


        public:
            Transform(
                const sf::Vector2f& position,
                const sf::Vector2f& dimension,
                const sf::Vector2f& direction,
                const sf::Vector2f& scale,
                const double rotation,
                const double speed,
                const std::size_t zIndex
            );

            Transform(
                const sf::Vector2f& position,
                const sf::Vector2f& direction,
                const double speed,
                const std::size_t zIndex
            );

            Transform(
                const std::size_t zIndex
            );

            Transform();

        public:
            sf::Vector2f position, dimension, direction, scale;
            double rotation, speed;
            std::size_t zIndex;
        
        public:
            float top();
            float bottom();
            float right();
            float left();
            void setTop(const float top);
            void setBottom(const float bottom);
            void setLeft(const float left);
            void setRight(const float right);
            
            sf::Vector2f move(const double dt);
            sf::Vector2f move(const sf::Vector2f& pos);

    };
    
} // namespace og


#endif