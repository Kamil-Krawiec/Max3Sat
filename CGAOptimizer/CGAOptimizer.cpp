#include "CGAOptimizer.h"

CGAOptimizer::CGAOptimizer(int sizeOfPopulation, double crossingProbability, double mutationProbability){

    this->sizeOfPopulation=sizeOfPopulation;
    this->crossingProbability = crossingProbability;
    this->mutationProbability= mutationProbability;
}

CGAOptimizer::CGAOptimizer() {
    sizeOfPopulation=DEFAULT_POPULATION_SIZE;
    crossingProbability=DEFAULT_CROSSING_PROBABILITY;
    mutationProbability=DEFAULT_MUTATION_PROBABILITY;
}

CGAOptimizer::~CGAOptimizer() {

}


