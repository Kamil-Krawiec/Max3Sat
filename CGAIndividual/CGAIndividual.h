#ifndef UNTITLED_CGAINDIVIDUAL_H
#define UNTITLED_CGAINDIVIDUAL_H


#include <vector>

class CGAIndividual {



    CGAIndividual* cgaMutation(CGAIndividual* child);
    CGAIndividual* cgaCrossover(CGAIndividual* child1,CGAIndividual* child2);




private:
    std::vector<bool> genotype;
    double fitness;



};


#endif //UNTITLED_CGAINDIVIDUAL_H
