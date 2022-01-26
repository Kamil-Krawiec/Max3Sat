#include "CGAIndividual.h"

//----------------------------CONSTRUCTORS----------------------------
CGAIndividual::CGAIndividual() {
    fitness = DEFAULT_FITNESS;
    populationSize = DEFAULT_POPULATION_SIZE;
    genotype = new std::vector<bool>;
    genotype->reserve(DEFAULT_POPULATION_SIZE);
}

CGAIndividual::CGAIndividual(const CGAIndividual* pcOther) {

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

    for (int i = 0; i != genotype->size(); i++) {
        if (randomNumber(100) < mutationProb * 100) {
            genotype->at(i) = !genotype->at(i);
        }
    }

    return this;
}

//choose parent
CGAIndividual *CGAIndividual::cgaChooseParent(std::vector<CGAIndividual *> population) {
    std::vector<CGAIndividual*> tournament;

    for(int i=0; i<population.size();i+=2){

        int first = randomNumber(population.size()) - 1;
        int second = randomNumber(population.size()) - 1;

        if(population[first]->fitness > population[second]->fitness){
            tournament.push_back(new CGAIndividual(population[first]));
        }else{
            tournament.push_back(new CGAIndividual(population[second]));
        }

    }

    if(population.size()==1){
        CGAIndividual* newOne = new CGAIndividual(population[0]);

        tournament.shrink_to_fit();

        return newOne;
    }

    return cgaChooseParent(tournament);
}

//crossover
CGAIndividual *CGAIndividual::cgaCrossover(CGAIndividual *parent1, CGAIndividual *parent2, double crossingProb) {

    CGAIndividual* newOne = new CGAIndividual(parent1);

    if (randomNumber(100) > crossingProb * 100) return newOne;

    int cuttingIndex = randomNumber(populationSize - 1);

    for (std::vector<CClause *>::size_type i = 0; i != parent1->genotype->size(); i++) {
        if (i < cuttingIndex) {
            newOne->genotype->at(i) = parent1->genotype->at(i);
        } else {
            newOne->genotype->at(i) = parent2->genotype->at(i);
        }
    }

    return newOne;
}

//fitness
double CGAIndividual::dFitness(CMax3SatProblem &max3SatProblem) {
    fitness = max3SatProblem.iCompute(genotype) / numberOfClauses;
    if(fitness==1) this->vShowResult();
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
    std::cout << "Best solution in fitness (completed/all) : " << fitness * 100 << "%" << std::endl;
    std::cout <<"Completed clauses: " << round((double) fitness * numberOfClauses) << std::endl;
    std::cout << "Binary coded: ";
    for (int i = 0; i < populationSize; i++) {
        std::cout << genotype->at(i);
    }

}

CGAIndividual::~CGAIndividual() {
    genotype->clear();
    delete genotype;
}







