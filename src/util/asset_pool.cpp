#include "../../include/util/asset_pool.hpp"


og::AssetPool* og::AssetPool::instance = nullptr;



og::AssetPool* og::AssetPool::getInstance() {
    if (!instance) {
        instance = new og::AssetPool();
    }
    return instance;
}



og::AssetPool::AssetPool() {
    
}


og::AssetPool::~AssetPool() {
    for (auto& pair : this->texturePool) {
        std::cout << "Deleting " << pair.first << " Texture\n";
        delete pair.second;
    }
    for (auto& pair : this->fontPool) {
        std::cout << "Deleting " << og::fontPathById.at(pair.first) << " Font\n";
        delete pair.second;
    }
    
    this->texturePool.clear();
}



void og::AssetPool::loadTexture(sf::Sprite& sprite, const std::string& texturePath) {
    if (this->texturePool.find(texturePath) == this->texturePool.end()) {
        sf::Texture* t = new sf::Texture();
        t->loadFromFile(texturePath);
        this->texturePool.insert({texturePath, t});
    }

    sf::Texture* texture = this->texturePool.at(texturePath);
    sprite.setTexture(*texture);
}


void og::AssetPool::rmvTexture(const std::string& path) {
    if (this->texturePool.find(path) != this->texturePool.end()) {
        sf::Texture* t = this->texturePool.at(path);
        this->texturePool.erase(path);
        std::cout << "Deleting " << path << " Texture\n";
        delete t;
    }
}


void og::AssetPool::loadFont(sf::Text& text, const og::FontId& fontId) {
    if (this->fontPool.find(fontId) == this->fontPool.end()) {
        sf::Font* font = new sf::Font();
        font->loadFromFile(og::fontPathById.at(fontId));
        this->fontPool.insert({fontId, font});
    }
    sf::Font* f = this->fontPool.at(fontId);
    text.setFont(*f);
}