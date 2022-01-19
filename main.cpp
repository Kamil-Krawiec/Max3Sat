#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {


    CGAOptimizer* optimizer = new CGAOptimizer();
    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/m3s_50_0.txt");
    optimizer->vRunIteration();
    optimizer->showResults();

    return 0;
}
