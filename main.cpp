#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {

    CGAOptimizer* optimizer = new CGAOptimizer(150,0.8,0.1);

    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/m3s_150_1.txt");

    int from=0;
    int to=10;

    while(from++<to){
        optimizer->vRunIteration();
    }

    optimizer->vShowResults();
    delete optimizer;

    return 0;
}
