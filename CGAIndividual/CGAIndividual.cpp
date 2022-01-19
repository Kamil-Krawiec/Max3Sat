#include <random>
#include "CGAIndividual.h"

CGAIndividual *CGAIndividual::cgaMutation(double mutationProb) {

    for (std::vector<bool>::size_type i = 0; i != genotype.size(); i++){
        if(randomNumber(100)>mutationProb*100){
            genotype[i]=!genotype[i];
        }
    }
    return this;
}

std::tuple<CGAIndividual*, CGAIndividual*> CGAIndividual::tupleCrossover(CGAIndividual *parent1, CGAIndividual *parent2) {

    CGAIndividual* newParent1;
    CGAIndividual* newParent2;

    int cuttingIndex = randomNumber(populationSize);
    for (std::vector<CClause *>::size_type i = 0; i != genotype.size(); i++) {
        if(i<cuttingIndex){
            newParent1->genotype.push_back(parent1->genotype[i]);
            newParent2->genotype.push_back(parent2->genotype[i]);
        }else{
            newParent1->genotype.push_back(parent2->genotype[i]);
            newParent2->genotype.push_back(parent1->genotype[i]);
        }

    }

    return {newParent1,newParent2};
}

CGAIndividual *CGAIndividual::cgaChooseParent(std::vector<CGAIndividual *> population) {
    std::cout<<this->randomNumber(populationSize);
    int first = randomNumber(populationSize);
    int second = randomNumber(populationSize);

    if (first != second) {
        population[first]->fitness > population[second]->fitness ? population[first] : population[second];
    } else {
        cgaChooseParent(population);
    }

    return nullptr;
}

double CGAIndividual::dFitness(CMax3SatProblem &max3SatProblem) {
    fitness = max3SatProblem.iCompute(genotype) / populationSize;
    return fitness;
}

void CGAIndividual::vInitialize(CMax3SatProblem &max3SatProblem, int sizeOfPopulation) {
    populationSize = sizeOfPopulation;
    for (int i = 0; i < sizeOfPopulation; i++) {
        genotype.push_back(randomBool());
    }

    dFitness(max3SatProblem);
}

bool CGAIndividual::randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine(100));
    return gen();
}

int CGAIndividual::randomNumber(int max) {
    static auto gen = std::bind(std::uniform_int_distribution<>(0, max), std::default_random_engine(111));
    return 10;
}
