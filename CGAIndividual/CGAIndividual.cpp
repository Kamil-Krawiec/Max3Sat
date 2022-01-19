#include <random>
#include "CGAIndividual.h"

CGAIndividual *CGAIndividual::cgaMutation(CGAIndividual *child) {
    return nullptr;
}

CGAIndividual *CGAIndividual::cgaCrossover(CGAIndividual *child1, CGAIndividual *child2) {
    return nullptr;
}

CGAIndividual *CGAIndividual::cgaChooseParent(std::vector<CGAIndividual *> population) {
    return nullptr;
}

double CGAIndividual::dFitness(CMax3SatProblem& max3SatProblem, int sizeOfPopulation) {

    fitness=max3SatProblem.iCompute(genotype)/sizeOfPopulation;
    return fitness;
}

void CGAIndividual::vInitialize(CMax3SatProblem& max3SatProblem,int sizeOfPopulation) {
    srand (time(NULL));
    
    for(int i=0;i<sizeOfPopulation;i++){
        genotype.push_back(randomBool());
    }

    dFitness(max3SatProblem,sizeOfPopulation);
}

bool CGAIndividual::randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine(100));
    return gen();
}

