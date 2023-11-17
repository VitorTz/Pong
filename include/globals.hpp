#ifndef OUGI_GLOBALS_HPP
#define OUGI_GLOBALS_HPP
#include "window/mouse.hpp"
#include "window/keyboard.hpp"
#include "util/asset_pool.hpp"


namespace og {

    extern og::Mouse* mouse;
    extern og::Keyboard* keyboard;
    extern og::AssetPool* assetPool;
    
    void initGlobals();    
    void deleteGlobals();

    
} // namespace og



#endif