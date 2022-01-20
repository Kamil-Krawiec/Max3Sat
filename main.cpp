#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {


    CGAOptimizer* optimizer = new CGAOptimizer();
    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/test1.txt");
    optimizer->vRunIteration();
    optimizer->vShowResults();

    return 0;
}
