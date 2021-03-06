#ifndef UNTITLED_CGAINDIVIDUAL_H
#define UNTITLED_CGAINDIVIDUAL_H
#define DEFAULT_POPULATION_SIZE 50
#define DEFAULT_FITNESS 0.0

#include <vector>
#include "../CMax3SatProblem/CMax3SatProblem.h"
#include <random>

class CGAIndividual {

public:
    //constructors
    CGAIndividual();

    CGAIndividual(const CGAIndividual* pcOther);

    CGAIndividual(int populationSize);

    //must have functions
    void vInitialize(CMax3SatProblem& max3SatProblem);

    CGAIndividual *cgaMutation(double mutationProb,CMax3SatProblem& max3SatProblem);

    CGAIndividual* cgaCrossover(CGAIndividual *parent1, CGAIndividual *parent2,double crossingProb, CMax3SatProblem& max3SatProblem);

    double dFitnessFirst(CMax3SatProblem &max3SatProblem);

    CGAIndividual *cgaChooseParent(std::vector<CGAIndividual *> population);

    //my functions

    bool randomBool();

    double dNewFitness(double difference);

    int randomNumber(int max);

    double getFitness() const;

    void vShowResult();

    virtual ~CGAIndividual();

private:
    int populationSize;
    int numberOfClauses;
    std::vector<bool>* genotype;
    double fitness;

};


#endif //UNTITLED_CGAINDIVIDUAL_H
