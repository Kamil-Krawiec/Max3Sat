#include "CClausule.h"


bool CClausule::bCheckClausule() {
    return boolFirst || boolMiddle || boolLast;
}

bool CClausule::bSetClausule(bool bfirst, bool bmiddle, bool blast) {

    boolFirst = (first < 0) == !bfirst;
    boolMiddle = (middle < 0) == !bmiddle;
    boolLast = (last < 0) == !blast;

    return bCheckClausule();
}

CClausule::CClausule(int first, int middle, int last) {
    this->first = first;
    this->middle = middle;
    this->last = last;
}
