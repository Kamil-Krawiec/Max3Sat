#include "CMax3SatProblem.h"

//----------------------------CONSTRUCTORS----------------------------
CMax3SatProblem::CMax3SatProblem(int sizeOfPopulation) {
    for (int i = 0; i < sizeOfPopulation; i++) {
        std::vector<CClause *> empty;
        numberToClauses.push_back(empty);
    }
}

//----------------------------MUST HAVE FUNCTIONS----------------------------

bool CMax3SatProblem::bLoad(const std::string& path,int sizeOfPopulation) {

    std::ifstream file;

    file.open(path);

    if (!file) {
        std::cout << "Unable to open file " << path << std::endl;
        return false;
    }


    vectorNumbers = new std::vector<Number*>;

    for(int i=0;i<sizeOfPopulation;i++){
        vectorNumbers->push_back(new Number(i));
    }

    allClauses=0;

    std::string bracket, x1, x2, x3;
    while (file >> bracket >> x1 >> x2 >> x3 >> bracket) {

        int first = std::atoi(x1.c_str());
        int middle = std::atoi(x2.c_str());
        int last = std::atoi(x3.c_str());

        CClause *newClause = new CClause(vectorNumbers->at(abs(first)),first>=0? 1:0,
                                           vectorNumbers->at(abs(middle)),middle>=0? 1:0,
                                           vectorNumbers->at(abs(last)),last>=0? 1:0);

        numberToClauses[abs(first)].push_back(newClause);
        numberToClauses[abs(middle)].push_back(newClause);
        numberToClauses[abs(last)].push_back(newClause);

        allClauses++;
    }
    file.close();
    return true;
}

double CMax3SatProblem::iCompute(std::vector<bool>* solution) {

    int trueClauses = 0;

    //setting new state to number
    for(int i=0; i<solution->size();i++){
        vectorNumbers->at(i)->setState(solution->at(i));
    }

    for(int i=0; i<numberToClauses.size();i++){
        for(int j=0; j<numberToClauses[i].size();j++){
            CClause* subject = numberToClauses[i][j];
            if(!subject->isVerified()){
                if(subject->bCheckClause()) trueClauses++;
                subject->setVerified(true);
            }
        }
    }

    for(int i=0; i<numberToClauses.size();i++){
        for(int j=0; j<numberToClauses[i].size();j++){
            CClause* subject = numberToClauses[i][j];
            subject->setVerified(false);
        }
    }


    return (double) trueClauses;
}

//----------------------------MY FUNCTIONS----------------------------
CMax3SatProblem::~CMax3SatProblem() {
    for (int i = 0; i != numberToClauses.size(); i++) {
        for (int j = 0; j != numberToClauses[i].size(); j++) {
            numberToClauses[i].shrink_to_fit();
        }
    }

    numberToClauses.shrink_to_fit();

    for(int i=0;i<vectorNumbers->size();i++){
        delete vectorNumbers->at(i);
    }

    vectorNumbers->shrink_to_fit();
    delete vectorNumbers;
}

int CMax3SatProblem::getAllClauses() const {
    return allClauses;
}

