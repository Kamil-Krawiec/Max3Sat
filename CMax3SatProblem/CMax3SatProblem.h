
#ifndef UNTITLED_CMAX3SATPROBLEM_H
#define UNTITLED_CMAX3SATPROBLEM_H

#include <string>
#include <vector>
#include "../CClause/CClausule.h"


class CMax3SatProblem {
public:
    CMax3SatProblem(int numberOfPopulation);

    bool bLoad(std::string path);

    int iCompute(std::vector<bool> solution);

private:
    std::vector<CClausule *> numberPointingToClausule;

};


#endif //UNTITLED_CMAX3SATPROBLEM_H
