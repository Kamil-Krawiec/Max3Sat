#include "CGAOptimizer.h"

CGAOptimizer::CGAOptimizer(int sizeOfPopulation, double crossingProbability, double mutationProbability) {

    this->sizeOfPopulation = sizeOfPopulation;
    this->crossingProbability = crossingProbability;
    this->mutationProbability = mutationProbability;

}

CGAOptimizer::CGAOptimizer() {
    sizeOfPopulation = DEFAULT_POPULATION_SIZE;
    crossingProbability = DEFAULT_CROSSING_PROBABILITY;
    mutationProbability = DEFAULT_MUTATION_PROBABILITY;
}

CGAOptimizer::~CGAOptimizer() {

}

void CGAOptimizer::vInitialize(std::string path) {
    max3sat = new CMax3SatProblem(sizeOfPopulation);
    max3sat->bLoad(path);

    for (int i = 0; i < sizeOfPopulation; i++) {
        population.push_back(new CGAIndividual());
        population[i]->vInitialize(*max3sat, sizeOfPopulation);
    }
    parent1 = new CGAIndividual(sizeOfPopulation);
    parent2 = new CGAIndividual(sizeOfPopulation);
    child1 = new CGAIndividual(sizeOfPopulation);
    child2 = new CGAIndividual(sizeOfPopulation);

}

void CGAOptimizer::vRunIteration() {
    newPopulation.clear();
    int counter=0;
    while ( counter < population.size()) {

        parent1 = parent1->cgaChooseParent(population);
        parent2 = parent2->cgaChooseParent(population);

        child1= child1->cgaCrossover(parent1, parent2);
        child2= child2->cgaCrossover(parent2,parent1);

        child1->cgaMutation(mutationProbability);
        child1->dFitness(*max3sat);
        child2->cgaMutation(mutationProbability);
        child2->dFitness(*max3sat);

        newPopulation.push_back(child1);
        newPopulation.push_back(child2);
        counter+=2;
    }
    population = newPopulation;

}

void CGAOptimizer::showResults() {
    max3sat->showBestSolution();
}










