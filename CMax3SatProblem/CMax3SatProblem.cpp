#include "CMax3SatProblem.h"

//----------------------------CONSTRUCTORS----------------------------
CMax3SatProblem::CMax3SatProblem(int sizeOfPopulation) {
    for (int i = 0; i < sizeOfPopulation; i++) {
        std::vector<CClause *> empty;
        numberToClauses.push_back(empty);
    }
}

//----------------------------MUST HAVE FUNCTIONS----------------------------

bool CMax3SatProblem::bLoad(const std::string &path, int sizeOfPopulation) {

    std::ifstream file;

    file.open(path);

    if (!file) {
        std::cout << "Unable to open file " << path << std::endl;
        return false;
    }


    vectorNumbers = new std::vector<Number *>;

    for (int i = 0; i < sizeOfPopulation; i++) {
        vectorNumbers->push_back(new Number(i));
    }

    std::string bracket, x1, x2, x3;
    std::set<int> keys;


    while (file >> bracket >> x1 >> x2 >> x3 >> bracket) {


        int first = std::atoi(x1.c_str());
        int middle = std::atoi(x2.c_str());
        int last = std::atoi(x3.c_str());

        CClause *newClausule = new CClause(vectorNumbers->at(abs(first)), first >= 0 ? 0 : 1,
                                           vectorNumbers->at(abs(middle)), middle >= 0 ? 0 : 1,
                                           vectorNumbers->at(abs(last)), last >= 0 ? 0 : 1);


        keys.insert(abs(first));
        keys.insert(abs(middle));
        keys.insert(abs(last));


        for (auto key: keys) {
            numberToClauses[key].push_back(newClausule);
        }

        vectorOfAllClauses.push_back(newClausule);
        keys.clear();
    }

    allClauses = vectorOfAllClauses.size();

    file.close();
    return true;
}

double CMax3SatProblem::iCompute(std::vector<bool> *solution) {

    int trueClauses = 0;

    //setting new state to number
    for (int i = 0; i < solution->size(); i++) {
        vectorNumbers->at(i)->setState(solution->at(i));
    }

    for (int i = 0; i < allClauses; i++) {
        if (vectorOfAllClauses.at(i)->bCheckClause()) trueClauses++;
    }


    return (double) trueClauses;
}

//----------------------------MY FUNCTIONS----------------------------

int CMax3SatProblem::getAllClauses() const {
    return allClauses;
}

double CMax3SatProblem::iCountChangedClauses(int changeAt) {
    double result = 0;
    for (int i = 0; i < numberToClauses.at(changeAt).size(); i++) {
        if (numberToClauses.at(changeAt).at(i)->bCheckClause()) result++;
    }

    return result;
}

double CMax3SatProblem::iComputeForChangedGen(int changeAt) {

    Number *current = vectorNumbers->at(changeAt);

    double beforeChange = iCountChangedClauses(changeAt);

    current->setState(!current->getState());

    double afterChange = iCountChangedClauses(changeAt);

    if (beforeChange >= afterChange) current->setState(!current->getState());

    return afterChange - beforeChange;
}

CMax3SatProblem::~CMax3SatProblem() {

    for (int i = 0; i != numberToClauses.size(); i++) {
        for (int j = 0; j != numberToClauses[i].size(); j++) {
            numberToClauses[i].shrink_to_fit();
        }
    }

    numberToClauses.shrink_to_fit();

    for (int i = 0; i < vectorNumbers->size(); i++) {
        delete vectorNumbers->at(i);
    }

    vectorNumbers->shrink_to_fit();
    delete vectorNumbers;

    vectorOfAllClauses.shrink_to_fit();
}

