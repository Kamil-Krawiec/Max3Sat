#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {


    CGAOptimizer* optimizer = new CGAOptimizer(150,0.6,0.1);

    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/m3s_150_3.txt");
    int from=0;
    int to=1;
    while(from++<to){
        optimizer->vRunIteration();
    }

    optimizer->vShowResults();
    delete optimizer;

    return 0;
}
