#include "KoffeeKrew-AutoScape.h"
#include <iostream>
#include <thread>

int main()
{
    AutoSplasher splasher;

    std::thread clickThread([&splasher]()
        {
            splasher.start();
        });

    std::cout << "Press Enter to stop AutoSplasher...\n";
    std::cin.get(); // Wait for user input

    splasher.stop();
    clickThread.join();

    return 0;
}