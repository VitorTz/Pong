#ifndef PONG_CPU_HPP
#define PONG_CPU_HPP
#include "player.hpp"


namespace po {


    class Cpu : public po::Player {

        protected:
            void updateDirection() override;

        public:
            Cpu();
            void update(double dt) override;

    };
    
} // namespace po


#endif