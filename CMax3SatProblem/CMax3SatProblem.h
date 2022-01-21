
#ifndef UNTITLED_CMAX3SATPROBLEM_H
#define UNTITLED_CMAX3SATPROBLEM_H

#include <string>
#include <vector>
#include "../CClause/CClause.h"
#include "../CClause/Number.h"
#include <fstream>
#include <iostream>


class CMax3SatProblem {

public:
    //constructor
    CMax3SatProblem(int sizeOfPopulation);

    //must have functions
    bool bLoad(const std::string& path,int sizeOfPopulation);

    double iCompute(std::vector<bool> *solution);

    //my functions
    int getAllClauses() const;

    virtual ~CMax3SatProblem();

private:
    std::vector<std::vector<CClause *>> numberToClauses;
    std::vector<Number*>* vectorNumbers;
    int allClauses;
};


#endif //UNTITLED_CMAX3SATPROBLEM_H
