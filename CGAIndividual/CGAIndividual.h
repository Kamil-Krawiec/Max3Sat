#ifndef UNTITLED_CGAINDIVIDUAL_H
#define UNTITLED_CGAINDIVIDUAL_H


#include <vector>
#include "../CMax3SatProblem/CMax3SatProblem.h"

class CGAIndividual {

public:
    void vInitialize(CMax3SatProblem& max3SatProblem,int sizeOfPopulation);

    CGAIndividual *cgaMutation(CGAIndividual *child);

    CGAIndividual *cgaCrossover(CGAIndividual *child1, CGAIndividual *child2);

    double dFitness(CMax3SatProblem& max3SatProblem, int sizeOfPopulation);

    CGAIndividual *cgaChooseParent(std::vector<CGAIndividual *> population);

    bool randomBool();


private:
    std::vector<bool> genotype;
    double fitness;

};


#endif //UNTITLED_CGAINDIVIDUAL_H
