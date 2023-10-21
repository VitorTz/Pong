#ifndef PONG_CPU_HPP
#define PONG_CPU_HPP
#include "player.hpp"
#include "ball.hpp"
#include "../timer.hpp"


namespace po {


    class Cpu : public po::Player {

        private:
            po::Ball* ball;
            po::Timer timer;

        protected:
            void updateDirection() override;

        public:
            Cpu();
            void update(double dt) override;
            void setGameBall(po::Ball* ball);
            void resetPos() override;
    };
    
} // namespace po


#endif