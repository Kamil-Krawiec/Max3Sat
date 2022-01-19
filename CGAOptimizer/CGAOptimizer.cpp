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

void CGAOptimizer::vInitialize(std::string path) {
    max3sat = new CMax3SatProblem(sizeOfPopulation);
    max3sat->bLoad(path);

    for (int i = 0; i < sizeOfPopulation; i++) {
        population.push_back(new CGAIndividual());
        population[i]->vInitialize(*max3sat,sizeOfPopulation);
    }


}






