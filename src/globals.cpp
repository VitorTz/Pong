#include "../include/globals.hpp"


og::Mouse* og::mouse = nullptr;


og::Keyboard* og::keyboard = nullptr;


og::AssetPool* og::assetPool = nullptr;


void og::initGlobals() {
    og::assetPool = og::AssetPool::getInstance();
    og::mouse = og::Mouse::getInstance();
    og::keyboard = og::Keyboard::getInstance();
}


void og::deleteGlobals() {
    delete og::assetPool;
    delete og::mouse;
    delete og::keyboard;
}