#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {

    int i = std::atoi("-41");

    CGAOptimizer* optimizer = new CGAOptimizer();
    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/m3s_50_0.txt");


    return 0;
}
