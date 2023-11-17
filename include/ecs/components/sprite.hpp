#ifndef OUGI_SPRITE_HPP
#define OUGI_SPRITE_HPP
#include "../ecs.hpp"


namespace og {


    class Sprite : public og::Component {

        private:
            std::string currentTexturePath;
            sf::Sprite sprite;
            sf::Vector2f dimension;

        public:

            Sprite(const std::string& name, const std::string& texturePath);
            Sprite(const std::string& name, const sf::Sprite& sprite);
            Sprite(const std::string& name);
            ~Sprite();
            void changeTexture(const std::string& texturePath);
            void changeSprite(const sf::Sprite& sprite);
            void draw(sf::RenderWindow& window) override;
            void setGameObj(og::GameObj* gameObj) override;
            void setColor(const sf::Color& color);
            sf::Vector2f spriteSize();

    };
    
} // namespace o


#endif