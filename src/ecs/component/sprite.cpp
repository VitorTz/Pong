#include "../../../include/ecs/components/sprite.hpp"



og::Sprite::Sprite(
    const std::string& name,
    const std::string& texturePath
) : og::Component(name) {
    this->changeTexture(texturePath);
}


og::Sprite::Sprite(
    const std::string& name,
    const sf::Sprite& sprite
) : og::Component(name), sprite(sprite) {
    this->changeSprite(sprite);
}


og::Sprite::Sprite(
    const std::string& name
) : og::Component(name) {
    
}


og::Sprite::~Sprite() {
    og::assetPool->rmvTexture(this->currentTexturePath);
}


void og::Sprite::changeSprite(const sf::Sprite& sprite) {
    og::assetPool->rmvTexture(this->currentTexturePath);
    this->sprite = sprite;
    this->dimension = this->spriteSize();
    this->sprite.setOrigin(this->dimension.x / 2, this->dimension.y / 2);
    if (this->gameObj != nullptr) {
        this->gameObj->getTransform()->dimension = this->dimension;
    }
}


void og::Sprite::changeTexture(const std::string& texturePath) {
    og::assetPool->rmvTexture(this->currentTexturePath);
    this->currentTexturePath = texturePath;
    og::assetPool->loadTexture(this->sprite, this->currentTexturePath);
    this->dimension = this->spriteSize();
    this->sprite.setOrigin(this->dimension.x / 2, this->dimension.y / 2);
    if (this->gameObj != nullptr) {
        this->gameObj->getTransform()->dimension = this->dimension;
    }
}


void og::Sprite::draw(sf::RenderWindow& window) {
    if (this->gameObj != nullptr) {
        og::Transform* t = this->gameObj->getTransform();
        sf::Vector2f posOffSet(this->dimension.x / 2,this->dimension.y / 2);
        sf::Vector2f posToDraw = t->position + posOffSet;
        this->sprite.setPosition(posToDraw);
        this->sprite.setRotation(t->rotation);
        this->sprite.setScale(t->scale);
        window.draw(this->sprite);
    }
}


sf::Vector2f og::Sprite::spriteSize() {
    return (sf::Vector2f) this->sprite.getTexture()->getSize();
}


void og::Sprite::setGameObj(og::GameObj* gameObj) {
    og::Component::setGameObj(gameObj);
    this->gameObj->getTransform()->dimension = this->dimension;
}


void og::Sprite::setColor(const sf::Color& color) {
    this->sprite.setColor(color);
}