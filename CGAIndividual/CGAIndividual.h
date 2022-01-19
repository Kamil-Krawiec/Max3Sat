#ifndef UNTITLED_CGAINDIVIDUAL_H
#define UNTITLED_CGAINDIVIDUAL_H


#include <vector>
#include "../CMax3SatProblem/CMax3SatProblem.h"

class CGAIndividual {

public:
    void vInitialize(CMax3SatProblem& max3SatProblem,int sizeOfPopulation);

    CGAIndividual *cgaMutation(double mutationProb);

    std::tuple<CGAIndividual*,CGAIndividual*> tupleCrossover(CGAIndividual *parent1, CGAIndividual *parent2);

    double dFitness(CMax3SatProblem& max3SatProblem);

    CGAIndividual *cgaChooseParent(std::vector<CGAIndividual *> population);

    bool randomBool();

    int randomNumber(int max);

private:
    int populationSize;
    std::vector<bool> genotype;
    double fitness;

};


#endif //UNTITLED_CGAINDIVIDUAL_H
