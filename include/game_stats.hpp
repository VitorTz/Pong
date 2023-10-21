#ifndef PONG_GAME_STATS_HPP
#define PONG_GAME_STATS_HPP
#include "constants.hpp"


namespace po {

    
    class GameStats {
        
        private:
            static GameStats* instance;
            int playerSpeed;
            int ballSpeed;
            int playerPoints;
            int cpuPoints;
            double timeElapsed;
            bool gameIsRunning;
            GameStats();

        public:
            static GameStats* getInstance();
            ~GameStats();
            void updateTimeElapsed(double dt);
            
            int getPlayerSpeed();
            int getBallSpeed();
            int getPlayerPoints();
            int getCpuPoints();
            double getTimeElapsed();
            
            void exitGame();
            bool isGameRunning();

            void speedUpGame();
            void resetPoints();
            void addPointToPlayer();
            void addPointToCpu();

    };  

    extern GameStats* gameStats;
        
    
} // namespace po


#endif