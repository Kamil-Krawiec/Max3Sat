#include <cmath>
#include "CClause.h"

CClause::CClause(Number *first, bool signFirst, Number *middle, bool signMiddle, Number *last, bool signLast) {
    this->first = first;
    this->middle = middle;
    this->last = last;

    this->negationFirst = signFirst;
    this->negationMiddle = signMiddle;
    this->negationLast = signLast;

}

bool CClause::bCheckClause() {
    return (negationFirst ? !first->getState() : first->getState()) ||
           (negationMiddle ? !middle->getState() : middle->getState()) ||
           (negationLast ? !last->getState() : last->getState());
}

CClause::~CClause() {

    delete first;
    delete middle;
    delete last;

}



