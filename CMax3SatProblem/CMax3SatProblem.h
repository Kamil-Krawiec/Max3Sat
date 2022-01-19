
#ifndef UNTITLED_CMAX3SATPROBLEM_H
#define UNTITLED_CMAX3SATPROBLEM_H

#include <string>
#include <vector>
#include "../CClause/CClausule.h"
#include <fstream>
#include <iostream>


class CMax3SatProblem {
public:
    CMax3SatProblem(int numberOfPopulation);

    virtual ~CMax3SatProblem();

    bool bLoad(std::string path);

    int iCompute(std::vector<bool> solution);

private:
    std::vector<std::vector<CClausule*>> numberPointingToClausules;

};


#endif //UNTITLED_CMAX3SATPROBLEM_H
