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
    population = new std::vector<CGAIndividual *>();
    newPopulation = new std::vector<CGAIndividual *>();
}

CGAOptimizer::~CGAOptimizer() {

}

void CGAOptimizer::vInitialize(std::string path) {
    max3sat = new CMax3SatProblem(sizeOfPopulation);
    max3sat->bLoad(path);


    for (int i = 0; i < sizeOfPopulation; i++) {
        CGAIndividual *newOne = new CGAIndividual(sizeOfPopulation);
        newOne->vInitialize(*max3sat);
        population->push_back(newOne);

    }

    parent1 = new CGAIndividual(sizeOfPopulation);
    parent2 = new CGAIndividual(sizeOfPopulation);
    child1 = new CGAIndividual(sizeOfPopulation);
    child2 = new CGAIndividual(sizeOfPopulation);

}

void CGAOptimizer::vRunIteration() {
    int counter = 0;
    vClearVector(newPopulation);
    while (counter < population->size()) {

        parent1 = parent1->cgaChooseParent(*population);
        parent2 = parent2->cgaChooseParent(*population);

        child1=child1->cgaCrossover(parent1, parent2, crossingProbability);
        child2=child2->cgaCrossover(parent2, parent1, crossingProbability);

        child1->cgaMutation(mutationProbability);
        child1->dFitness(*max3sat);
        child2->cgaMutation(mutationProbability);
        child2->dFitness(*max3sat);

        newPopulation->push_back(child1);
        newPopulation->push_back(child2);
        counter += 2;
    }

    child1= nullptr;
    child1= nullptr;
    parent1= nullptr;
    parent1= nullptr;

    vClearVector(population);

    population = newPopulation;

}

void CGAOptimizer::vShowResults() {
    vSortPopulation();
    CGAIndividual *bestSolution = population->at(0);
    bestSolution->vShowResult();

}

void CGAOptimizer::vSortPopulation() {
    sort(population->begin(), population->end(),
         [](CGAIndividual *l, CGAIndividual *r) { return l->getFitness() > r->getFitness(); });
}

void CGAOptimizer::vClearVector(std::vector<CGAIndividual *> *vec) {
    for (int i = 0; i < vec->size(); i++) {
        delete vec->at(i);
    }

    vec->clear();
}










