#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {

    CGAOptimizer* optimizer = new CGAOptimizer(50,0.8,0.1);

    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/m3s_50_0.txt");

    int from=0;
    int to=100;

    while(from++<to){
        optimizer->vRunIteration();
    }

    optimizer->vShowResults();
    delete optimizer;

    return 0;
}
