#include "Enemy.h"
#include <thread>
#include <chrono>

int main()
{
    Enemy e;

    while (e.Update())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
