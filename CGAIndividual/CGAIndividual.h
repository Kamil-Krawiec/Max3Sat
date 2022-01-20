#ifndef UNTITLED_CGAINDIVIDUAL_H
#define UNTITLED_CGAINDIVIDUAL_H
#define DEFAULT_POPULATION_SIZE 50
#define DEFAULT_FITNESS 0.0

#include <vector>
#include "../CMax3SatProblem/CMax3SatProblem.h"
#include <random>

class CGAIndividual {

public:
    CGAIndividual();

    CGAIndividual(int populationSize);

    void vInitialize(CMax3SatProblem& max3SatProblem,int sizeOfPopulation);

    CGAIndividual *cgaMutation(double mutationProb);

    CGAIndividual* cgaCrossover(CGAIndividual *parent1, CGAIndividual *parent2);

    double dFitness(CMax3SatProblem &max3SatProblem);


    CGAIndividual *cgaChooseParent(std::vector<CGAIndividual *> population);

    bool randomBool();

    int randomNumber(int max);

private:
    int populationSize;
    int numberOfClauses;
    std::vector<bool> genotype;
    double fitness;

};


#endif //UNTITLED_CGAINDIVIDUAL_H
