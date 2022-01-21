#include "CClause.h"

bool CClause::bCheckClausule() {
    return boolFirst || boolMiddle || boolLast;
}

CClause::CClause(int first, int middle, int last) {
    this->first = first;
    this->middle = middle;
    this->last = last;
    verified=false;
}

void CClause::vSetNumber(int number, bool newState) {
    if(number==first) boolFirst = (first < 0) == !newState;
    if(number==middle) boolMiddle = (middle < 0) == !newState;
    if(number==last) boolLast = (last < 0) == !newState;
}

bool CClause::isVerified() const {
    return verified;
}

void CClause::setVerified(bool verified) {
    this->verified = verified;
}

CClause::~CClause() {

}
