#include "CGAIndividual.h"

//----------------------------CONSTRUCTORS----------------------------
CGAIndividual::CGAIndividual() {
    fitness = DEFAULT_FITNESS;
    populationSize = DEFAULT_POPULATION_SIZE;
    genotype = new std::vector<bool>;
    genotype->reserve(DEFAULT_POPULATION_SIZE);
}

CGAIndividual::CGAIndividual(const CGAIndividual *pcOther) {

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
CGAIndividual *CGAIndividual::cgaMutation(double mutationProb, CMax3SatProblem &max3SatProblem) {

    for (int i = 0; i != genotype->size(); i++) {
        if (randomNumber(100) < mutationProb * 100) {
            double difference = max3SatProblem.iComputeForChangedGen(i);

            if (difference > 0) {
                genotype->at(i) = !genotype->at(i);
                dNewFitness(difference);
            }

        }
    }

    return this;
}

//choose parent
//tournament method with t=2;
CGAIndividual *CGAIndividual::cgaChooseParent(std::vector<CGAIndividual *> population){

    int first = randomNumber(population.size()) - 1;
    int second = randomNumber(population.size()) - 1;
    CGAIndividual *newOne;

    if(population.at(first)->getFitness()>population.at(second)->getFitness()){
        newOne = new CGAIndividual(population[first]);
    }else{
        newOne = new CGAIndividual(population[second]);
    }

    return newOne;
}
//crossover
CGAIndividual *CGAIndividual::cgaCrossover(CGAIndividual *parent1, CGAIndividual *parent2, double crossingProb,CMax3SatProblem &max3sat) {

    CGAIndividual *newOne = new CGAIndividual(parent1);

    if (randomNumber(100) > crossingProb * 100) return newOne;

    int cuttingIndex = randomNumber(populationSize - 1);

    for (std::vector<CClause *>::size_type i = 0; i != parent1->genotype->size(); i++) {
        if (i < cuttingIndex) {
            newOne->genotype->at(i) = parent1->genotype->at(i);
        } else {
            newOne->genotype->at(i) = parent2->genotype->at(i);
        }
    }

    newOne->dFitnessFirst(max3sat);

    return newOne;
}

//fitness counted for the first time
double CGAIndividual::dFitnessFirst(CMax3SatProblem &max3SatProblem) {
    fitness = max3SatProblem.iCompute(genotype) / numberOfClauses;
    return fitness;
}

//initialize
void CGAIndividual::vInitialize(CMax3SatProblem &max3SatProblem) {

    for (int i = 0; i < populationSize; i++) {
        genotype->push_back(randomBool());
    }

    numberOfClauses = max3SatProblem.getAllClauses();
    dFitnessFirst(max3SatProblem);
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
    std::cout << "Best solution in fitness (completed/all) : " << fitness * 100 << "%" << std::endl;
    std::cout << "Completed clauses: " << round((double) fitness * numberOfClauses) << std::endl;
    std::cout << "Binary coded: ";
    for (int i = 0; i < populationSize; i++) {
        std::cout << genotype->at(i);
    }
    return;
}

CGAIndividual::~CGAIndividual() {
    genotype->clear();
    delete genotype;
}

double CGAIndividual::dNewFitness(double difference) {

    fitness = (round((double) fitness * numberOfClauses) + difference) / numberOfClauses;

    if (fitness == 1) this->vShowResult();

    return fitness;
}







