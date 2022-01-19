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


}

void CGAOptimizer::vRunIteration() {
    newPopulation.clear();
    while (newPopulation.size() < population.size()) {

        parent1 = parent1->cgaChooseParent(population);
        parent2 = parent2->cgaChooseParent(population);
        auto[child1, child2] = tupleCrossing(parent1, parent2);
        child1->cgaMutation(mutationProbability);
        child2->cgaMutation(mutationProbability);
        newPopulation.push_back(child1);
        newPopulation.push_back(child2);
    }
    population = newPopulation;

    for (auto &individual: population) {
        individual->dFitness(*max3sat);
    }

}

std::tuple<CGAIndividual *, CGAIndividual *>
CGAOptimizer::tupleCrossing(CGAIndividual *parent1, CGAIndividual *parent2) {
    if (child1->randomNumber(100) % 100 > crossingProbability * 100) {
        return child2->tupleCrossover(parent1, parent2);
    } else {
        return {parent1, parent2};
    }

}

void CGAOptimizer::showResults() {
    max3sat->showBestSolution();
}










