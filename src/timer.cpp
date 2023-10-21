#include "../include/timer.hpp"


po::Timer::Timer(double timeToCount) : startTime(po::gameStats->getTimeElapsed()), timeToCount(timeToCount) {

}


void po::Timer::setTimeToCount(double time) {
    this->timeToCount = time;
    this->reset();
}


void po::Timer::reset() {
    this->startTime = po::gameStats->getTimeElapsed();
}


bool po::Timer::check() {
    bool r = (po::gameStats->getTimeElapsed() - this->startTime) >= this->timeToCount;
    if (r) this->reset();
    return r;
}