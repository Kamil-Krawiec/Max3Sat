#ifndef UNTITLED_CCLAUSE_H
#define UNTITLED_CCLAUSE_H


#include "Number.h"

class CClause {
public:
    CClause(Number *first,bool signFirst,Number *middle,bool signMiddle, Number *last,bool signLast);

    virtual ~CClause();

    bool bCheckClause();


private:
    Number* first;
    Number* middle;
    Number* last;

    bool negationFirst;
    bool negationMiddle;
    bool negationLast;

};


#endif //UNTITLED_CCLAUSE_H
