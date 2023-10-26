#include <iostream>
#include "Spot.h"
#include "Influence.h"
#include "Assists.h"

int main() {
    Spot location(5, 10, 'X');
    std::cout << "Spot Location: (" << std::get<0>(location.getLoc()) << ", " 
              << std::get<1>(location.getLoc()) << "), Category: " << location.getCategory() << std::endl;

    std::tuple<int, int> loc1 = Assists::createRandomLoc(10, 10);
    std::tuple<int, int> loc2 = Assists::createRandomLoc(10, 10);
    std::cout << "Distance between (" << std::get<0>(loc1) << ", " << std::get<1>(loc1) 
              << ") and (" << std::get<0>(loc2) << ", " << std::get<1>(loc2) << "): " 
              << Assists::evaluateDistance(loc1, loc2) << std::endl;

    return 0;
}
