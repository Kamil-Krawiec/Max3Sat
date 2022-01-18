#ifndef UNTITLED_CGAOPTIMIZER_H
#define UNTITLED_CGAOPTIMIZER_H


#include <vector>
#include "../CGAIndividual/CGAIndividual.h"

#define DEFAULT_POPULATION_SIZE 50
#define DEFAULT_CROSSING_PROBABILITY 0.60
#define DEFAULT_MUTATION_PROBABILITY 0.40


class CGAOptimizer {
public:
    CGAOptimizer(int sizeOfPopulation, double crossingProbability, double mutationProbability);
    CGAOptimizer();
    virtual ~CGAOptimizer();


private:
    int sizeOfPopulation;
    double crossingProbability;
    double mutationProbability;

    std::vector<CGAIndividual*> population;
    std::vector<CGAIndividual*> newPopulation;

    CGAIndividual* parent1;
    CGAIndividual* parent2;

    CGAIndividual* child1;
    CGAIndividual* child2;



};


#endif //UNTITLED_CGAOPTIMIZER_H
