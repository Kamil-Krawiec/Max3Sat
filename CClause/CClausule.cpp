#include "CClausule.h"


bool CClausule::bCheckClausule() {
    return boolFirst||boolMiddle||boolLast;
}

bool CClausule::bSetClausule(bool bfirst, bool bmiddle, bool blast) {

    boolFirst = (first < 0) == !bfirst;
    boolMiddle = (middle < 0) == !bmiddle;
    boolLast = (last < 0) == !blast;

    return bCheckClausule();
}
