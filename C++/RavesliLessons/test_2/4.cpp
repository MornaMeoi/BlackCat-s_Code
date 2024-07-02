#include <iostream>
#include "constants.h"

double towerHeight();
void printCurrentHeight(const double initial_height, const int current_time);

int main()
{
    const double height = towerHeight();
    for(int time = 0; time <= 5; ++time)
        printCurrentHeight(height, time);
    return 0;
}

double towerHeight()
{
    double height;
    std::cout << "Enter the initial height of the tower in meters: ";
    std::cin >> height;
    return height;
}

void printCurrentHeight(const double initial_height, const int current_time)
{
    std::cout << "At " << current_time << " seconds, the ball is ";
    const double height = initial_height - current_time*current_time / 2.0 * myConstants::g;
    if(height >= 0)
        std::cout << "at height: " << height << " meters.";
    else
        std::cout << "on the ground.";
    std::cout << std::endl;
}