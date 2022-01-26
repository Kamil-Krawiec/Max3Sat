#include <iostream>
#include "CGAOptimizer/CGAOptimizer.h"

int main() {

<<<<<<< HEAD
    CGAOptimizer* optimizer = new CGAOptimizer(50,0.80,0.1);
=======
    CGAOptimizer* optimizer = new CGAOptimizer(150,0.8,0.1);
>>>>>>> optimization

    optimizer->vInitialize("/Users/kamil/Desktop/TEP/Max3Sat/tests/m3s_150_1.txt");

    int from=0;
    int to=10;

    while(from++<to){
        if(from%100 == 0) std::cout<<from<<" iteracja"<<std::endl;
        optimizer->vRunIteration();
    }

    optimizer->vShowResults();
    delete optimizer;

    return 0;
}
