#include "CGAIndividual.h"

//----------------------------CONSTRUCTORS----------------------------
CGAIndividual::CGAIndividual() {
    fitness = DEFAULT_FITNESS;
    populationSize = DEFAULT_POPULATION_SIZE;
    genotype->reserve(DEFAULT_POPULATION_SIZE);
}

CGAIndividual::CGAIndividual(CGAIndividual *pcOther) {
    this->fitness = pcOther->fitness;
    this->populationSize = pcOther->populationSize;
    this->numberOfClauses = pcOther->numberOfClauses;
    this->genotype = new std::vector<bool>;
    this->genotype->resize(populationSize);

    for (int i = 0; i < populationSize; i++) {
        genotype->at(i) = pcOther->genotype->at(i);
    }

}

CGAIndividual::CGAIndividual(int populationSize) {
    this->populationSize = populationSize;
    genotype = new std::vector<bool>;
}

//----------------------------MUST HAVE FUNCTIONS----------------------------

//mutate fun
CGAIndividual *CGAIndividual::cgaMutation(double mutationProb) {

    for (std::vector<bool>::size_type i = 0; i != genotype->size(); i++) {
        if (randomNumber(100) < mutationProb * 100) {
            genotype->at(i) = !genotype->at(i);
        }
    }

    return this;
}

//choose parent
CGAIndividual *CGAIndividual::cgaChooseParent(std::vector<CGAIndividual *> population) {

    int first = randomNumber(populationSize) - 1;
    int second = randomNumber(populationSize) - 1;

    if (first != second) {
        return population[first]->fitness > population[second]->fitness ? (CGAIndividual *) (population[first])
                                                                        : (CGAIndividual *) (population[second]);
    } else {
        return cgaChooseParent(population);
    }

}

//crossover
CGAIndividual *CGAIndividual::cgaCrossover(CGAIndividual *parent1, CGAIndividual *parent2, double crossingProb) {

    if (randomNumber(100) > crossingProb * 100) return (CGAIndividual *) (parent1);

    int cuttingIndex = randomNumber(populationSize - 1);

    this->numberOfClauses = parent1->numberOfClauses;
    this->genotype->resize(populationSize);

    for (std::vector<CClause *>::size_type i = 0; i != parent1->genotype->size(); i++) {
        if (i < cuttingIndex) {
            this->genotype->at(i) = parent1->genotype->at(i);
        } else {
            this->genotype->at(i) = parent2->genotype->at(i);
        }
    }

    return (CGAIndividual *) (this);
}

//fitness
double CGAIndividual::dFitness(CMax3SatProblem &max3SatProblem) {
    fitness = max3SatProblem.iCompute(genotype) / numberOfClauses;
    return fitness;
}

//initialize
void CGAIndividual::vInitialize(CMax3SatProblem &max3SatProblem) {

    for (int i = 0; i < populationSize; i++) {
        genotype->push_back(randomBool());
    }

    numberOfClauses = max3SatProblem.getAllClauses();
    dFitness(max3SatProblem);
}

//----------------------------MY FUNCTIONS----------------------------

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
    std::cout <<"Complited clauses: " << round((double) fitness * numberOfClauses) << std::endl;
    std::cout << "Binary coded: ";
    for (int i = 0; i < populationSize; i++) {
        std::cout << genotype->at(i);
    }

}







