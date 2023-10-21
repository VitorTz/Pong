#ifndef PONG_TIMER_HPP
#define PONG_TIMER_HPP
#include "game_stats.hpp"


namespace po {


    class Timer {

        private:
            double startTime;
            double timeToCount;            

        public:
            Timer(double timeToCount);
            void setTimeToCount(double time);
            void reset();
            bool check();

    };  
    
} // namespace po


#endif