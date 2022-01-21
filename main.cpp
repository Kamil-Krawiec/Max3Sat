#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {


    CGAOptimizer* optimizer = new CGAOptimizer(50,0.6,0.1);

    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/m3s_50_0.txt");

    optimizer->vRunIteration();
    
    optimizer->vShowResults();

    return 0;
}
