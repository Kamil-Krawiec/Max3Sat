#include "CMax3SatProblem.h"

bool CMax3SatProblem::bLoad(std::string path) {
    std::ifstream file;
    file.open(path);

    if (!file) {
        std::cout<< "Unable to open file "<<path<<std::endl;
        return false;
    }

    std::string bracket,x1,x2,x3;

    while(file>> bracket >> x1 >> x2 >> x3 >> bracket){

        int first = std::atoi(x1.c_str());
        int middle = std::atoi(x2.c_str());
        int last = std::atoi(x3.c_str());

        CClausule* newClausule = new CClausule(first,middle,last);

        numberPointingToClausules[abs(first)].push_back(newClausule);
        numberPointingToClausules[abs(middle)].push_back(newClausule);
        numberPointingToClausules[abs(last)].push_back(newClausule);

    }

    file.close();
    return true;
}

int CMax3SatProblem::iCompute(std::vector<bool> solution) {
    int sum;


    return 0;
}

CMax3SatProblem::CMax3SatProblem(int numberOfPopulation){
    for(int i=0;i<numberOfPopulation;i++){
        std::vector<CClausule*> empty;
        numberPointingToClausules.push_back(empty);
    }
}

//TODO
CMax3SatProblem::~CMax3SatProblem() {


}



