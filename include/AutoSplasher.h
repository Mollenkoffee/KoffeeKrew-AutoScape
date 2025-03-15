#ifndef AUTOSPLASHER_H
#define AUTOSPLASHER_H

#include <windows.h>
#include <thread>
#include <random>
#include <atomic>

class AutoSplasher
{
    public:
        AutoSplasher();
        void start();
        void stop();
        bool isRunning() const;

    private:
        std::atomic<bool> running;
        std::mt19937 rng;
        std::uniform_int_distribution<int> distribution;

        void clickMouse();
        void clickLoop();
};

#endif // AUTOSPLASHER_H