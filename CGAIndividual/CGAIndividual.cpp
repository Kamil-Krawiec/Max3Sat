#include "CGAIndividual.h"

CGAIndividual::CGAIndividual() {
    fitness = DEFAULT_FITNESS;
    populationSize = DEFAULT_POPULATION_SIZE;
    genotype->reserve(DEFAULT_POPULATION_SIZE);
}


CGAIndividual::CGAIndividual(int populationSize) {
    this->populationSize = populationSize;
    genotype = new std::vector<bool>;

}


CGAIndividual *CGAIndividual::cgaMutation(double mutationProb) {

    for (std::vector<bool>::size_type i = 0; i != genotype->size(); i++) {
        if (randomNumber(100) < mutationProb * 100) {
            genotype->at(i) = !genotype->at(i);
        }
    }

    return this;
}


CGAIndividual *CGAIndividual::cgaChooseParent(std::vector<CGAIndividual *> population) {

    int first = randomNumber(populationSize) - 1;
    int second = randomNumber(populationSize) - 1;

    if (first != second) {
        return population[first]->fitness > population[second]->fitness ? population[first] : population[second];
    } else {
        return cgaChooseParent(population);
    }

}

CGAIndividual *CGAIndividual::cgaCrossover(CGAIndividual *parent1, CGAIndividual *parent2, double crossingProb) {

    if (randomNumber(100) > crossingProb * 100) return parent1;

    this->genotype->clear();
    this->genotype->reserve(populationSize);

    int cuttingIndex = randomNumber(populationSize - 1);

    this->numberOfClauses = parent1->numberOfClauses;
    this->fitness=0;

    for (std::vector<CClause *>::size_type i = 0; i != parent1->genotype->size(); i++) {
        if (i < cuttingIndex) {
            this->genotype->push_back(parent1->genotype->at(i));
        } else {
            this->genotype->push_back(parent2->genotype->at(i));
        }
    }

    return this;
}

double CGAIndividual::dFitness(CMax3SatProblem &max3SatProblem) {
    fitness = max3SatProblem.iCompute(genotype) / numberOfClauses;
    return fitness;
}

void CGAIndividual::vInitialize(CMax3SatProblem &max3SatProblem) {
    for (int i = 0; i < populationSize; i++) {
        genotype->push_back(randomBool());
    }
    numberOfClauses = max3SatProblem.getAllClauses();
    dFitness(max3SatProblem);
}

bool CGAIndividual::randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine(100));
    return gen();
}

int CGAIndividual::randomNumber(int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, max);
    return distrib(gen);
}

double CGAIndividual::getFitness() const {
    return fitness;
}

void CGAIndividual::vShowResult() {
    std::cout << "Best solution in fitness (complited/all) : " << fitness * 100 << "%" << std::endl;
    std::cout << "Complited clauses: " << (int) fitness * numberOfClauses << std::endl;
    std::cout << "Binary coded: ";
    for (int i = 0; i < populationSize; i++) {
        genotype->at(i);
    }

}






