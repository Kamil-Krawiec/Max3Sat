#include "CMax3SatProblem.h"

bool CMax3SatProblem::bLoad(std::string path) {

    std::ifstream file;
    file.open(path);

    if (!file) {
        std::cout << "Unable to open file " << path << std::endl;
        return false;
    }

    std::string bracket, x1, x2, x3;
    allClauses=0;

    while (file >> bracket >> x1 >> x2 >> x3 >> bracket) {

        int first = std::atoi(x1.c_str());
        int middle = std::atoi(x2.c_str());
        int last = std::atoi(x3.c_str());

        CClause *newClausule = new CClause(first, middle, last);

        numberPointingToClausules[abs(first)].push_back(newClausule);
        numberPointingToClausules[abs(middle)].push_back(newClausule);
        numberPointingToClausules[abs(last)].push_back(newClausule);
        allClauses++;
    }
    file.close();
    return true;
}

double CMax3SatProblem::iCompute(std::vector<bool>* solution) {

    int trueClauses = 0;

    for (std::vector<std::vector<CClause *>>::size_type i = 0; i != numberPointingToClausules.size(); i++) {
        for (std::vector<CClause *>::size_type j = 0; j != numberPointingToClausules[i].size(); j++) {
            numberPointingToClausules[i][j]->vSetNumber(i, solution->at(i));
        }
    }

    for (std::vector<std::vector<CClause *>>::size_type i = 0; i != numberPointingToClausules.size(); i++) {
        for (std::vector<CClause *>::size_type j = 0; j != numberPointingToClausules[i].size(); j++) {
            CClause *subject = numberPointingToClausules[i][j];

            if (!subject->isVerified()) {
                if(subject->bCheckClausule())trueClauses++;
            }
            subject->setVerified(true);

        }
    }

    for (std::vector<std::vector<CClause *>>::size_type i = 0; i != numberPointingToClausules.size(); i++) {
        for (std::vector<CClause *>::size_type j = 0; j != numberPointingToClausules[i].size(); j++) {
            CClause *subject = numberPointingToClausules[i][j];
            subject->setVerified(false);
        }
    }

    return (double) trueClauses;
}

CMax3SatProblem::CMax3SatProblem(int numberOfPopulation) {
    for (int i = 0; i < numberOfPopulation; i++) {
        std::vector<CClause *> empty;
        numberPointingToClausules.push_back(empty);
    }
}

//TODO
CMax3SatProblem::~CMax3SatProblem() {


}


int CMax3SatProblem::getAllClauses() const {
    return allClauses;
}





