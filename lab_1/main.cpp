#include <iostream>
#include "include/chocolate_slicer.h"

int main () {
    int barN, barM;
    
    std::cout << "Input chocolate bar size (n m):" << std::endl;
    std::cin >> barN >> barM;

    int slicesRequired = slicesCount(barN, barM);

    if (slicesRequired == 0) {
        std::cout << "Incorrect chocolate bar size (" << barN << " x " << barM << ")." << std::endl;
        return 1;
    }

    std::cout << slicesRequired << " slices required to cut your chocolate bar." << std::endl; 
    return 0;
}