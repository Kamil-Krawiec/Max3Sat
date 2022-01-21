#include <cmath>
#include "CClause.h"

CClause::CClause(Number *first,bool signFirst,Number *middle,bool signMiddle, Number *last,bool signLast)  {
    this->first = first;
    this->middle = middle;
    this->last = last;

    this->signFirst = signFirst;
    this->signMiddle = signMiddle;
    this->signLast = signLast;

    this->verified= false;
}

bool CClause::bCheckClause() {
    return (signFirst&&first->getState()) || (signMiddle&&middle->getState())  || (signLast&&last->getState()) ;
}

bool CClause::isVerified() const {
    return verified;
}

void CClause::setVerified(bool verified) {
    this->verified = verified;
}

CClause::~CClause() {

    delete first;
    delete middle;
    delete last;

}



