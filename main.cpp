#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {

    CGAOptimizer* optimizer = new CGAOptimizer(50,0.80,0.1);

    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/m3s_50_0.txt");

    int from=0;
    int to=1;

    while(from++<to){
        if(from%100 == 0) std::cout<<from<<" iteracja"<<std::endl;
        optimizer->vRunIteration();
    }

    optimizer->vShowResults();
    delete optimizer;

    return 0;
}
