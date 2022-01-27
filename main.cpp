#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {

    CGAOptimizer* optimizer = new CGAOptimizer(50,0.75,0.07);

    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/m3s_50_1.txt");

    int from=0;
    int to=10000;

    while(from++<to){
        if(from%100 == 0)
            std::cout<<from<<" iteration..."<<std::endl;
        optimizer->vRunIteration();
    }

    optimizer->vShowResults();
    delete optimizer;

    return 0;
}
