#include "AutoSplasher.h"
#include <iostream>
#include <chrono>

AutoSplasher::AutoSplasher() : running(false)
{
    std::random_device rd;
    rng = std::mt19937(rd());
    distribution = std::uniform_int_distribution<int>(0, 5); // Random time between 0s - 19 min (0 to 1140 seconds)
}

void AutoSplasher::start()
{
    running = true;
    std::cout << "[AutoSplasher] Started.\n";
    std::thread(&AutoSplasher::clickLoop, this).detach();
}

void AutoSplasher::stop()
{
    running = false;
    std::cout << "[AutoSplasher] Stopping...\n";
}

bool AutoSplasher::isRunning() const
{
    return running.load();
}

void AutoSplasher::clickMouse()
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> holdDuration(30, 150); // Random hold between 30ms - 150ms

    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(holdDuration(rng)));

    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));

    std::cout << "[AutoSplasher] Mouse Clicked.\n";
}

void AutoSplasher::clickLoop()
{
    while (running)
    {
        int waitTime = distribution(rng);
        std::cout << "[AutoSplasher] Next click in " << waitTime << " seconds.\n";
        std::this_thread::sleep_for(std::chrono::seconds(waitTime));

        if (running)
        {
            clickMouse();
        }
    }
}