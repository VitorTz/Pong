#include "../include/window/window.hpp"


int main() {   
    og::Window* w = og::Window::getInstance();
    w->run();
    delete w;
    return 0;
}