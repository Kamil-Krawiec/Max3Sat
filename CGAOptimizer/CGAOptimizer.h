#ifndef UNTITLED_CGAOPTIMIZER_H
#define UNTITLED_CGAOPTIMIZER_H


#include <vector>
#include "../CGAIndividual/CGAIndividual.h"
#include "../CMax3SatProblem/CMax3SatProblem.h"

#define DEFAULT_POPULATION_SIZE 50
#define DEFAULT_CROSSING_PROBABILITY 0.60
#define DEFAULT_MUTATION_PROBABILITY 0.10


class CGAOptimizer {
public:
    //constructors
    CGAOptimizer(int sizeOfPopulation, double crossingProbability, double mutationProbability);

    CGAOptimizer();

    //must have functions
    virtual ~CGAOptimizer();

    void vInitialize(std::string path);

    void vRunIteration();

    //my functions
    void vShowResults();

    void vSortPopulation();

    void vClearVector(std::vector<CGAIndividual*>* vector);

private:

    int sizeOfPopulation;
    double crossingProbability;
    double mutationProbability;

    std::vector<CGAIndividual *>* population;
    std::vector<CGAIndividual *>* newPopulation;

    CGAIndividual *parent1;
    CGAIndividual *parent2;

    CGAIndividual *child1;
    CGAIndividual *child2;

    CMax3SatProblem* max3sat;

};


#endif //UNTITLED_CGAOPTIMIZER_H
