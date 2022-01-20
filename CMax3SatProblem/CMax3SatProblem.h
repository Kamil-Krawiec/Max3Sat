
#ifndef UNTITLED_CMAX3SATPROBLEM_H
#define UNTITLED_CMAX3SATPROBLEM_H

#include <string>
#include <vector>
#include "../CClause/CClause.h"
#include <fstream>
#include <iostream>


class CMax3SatProblem {
public:
    CMax3SatProblem(int numberOfPopulation);

    virtual ~CMax3SatProblem();

    bool bLoad(std::string path);

    double iCompute(std::vector<bool> solution);

    void showBestSolution();

    int getAllClauses() const;

private:
    std::vector<std::vector<CClause*>> numberPointingToClausules;
    std::vector<bool> bestSolution;
    int completedClauses;
    int allClauses;
};


#endif //UNTITLED_CMAX3SATPROBLEM_H
