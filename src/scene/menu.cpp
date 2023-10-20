#include "../../include/scene/menu.hpp"
#include <iostream>


po::Menu::Menu(
    std::function<void(po::SceneId)>& changeScene
) : po::Scene(po::SceneId::Menu, changeScene) {
    std::cout << "CHanged to Menu\n";
} 