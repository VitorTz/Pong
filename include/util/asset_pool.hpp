#ifndef OUGI_ASSET_POOL_HPP
#define OUGI_ASSET_POOL_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "../font.hpp"


namespace og {

    class AssetPool {

        private:
            AssetPool();
            static AssetPool* instance;
            std::map<std::string, sf::Texture*> texturePool;
            std::map<og::FontId, sf::Font*> fontPool;
        
        public:
            static AssetPool* getInstance();
            ~AssetPool();
        
        public:
            void loadTexture(sf::Sprite& sprite, const std::string& texturePath);
            void rmvTexture(const std::string& texturePath);
            void loadFont(sf::Text& text, const og::FontId& fontId);
            

    };
    
} // namespace og


#endif