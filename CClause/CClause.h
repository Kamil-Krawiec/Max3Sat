#ifndef UNTITLED_CCLAUSE_H
#define UNTITLED_CCLAUSE_H


#include "Number.h"

class CClause {
public:
    CClause(Number *first,bool signFirst,Number *middle,bool signMiddle, Number *last,bool signLast);

    virtual ~CClause();

    bool bCheckClause();

    bool isVerified() const;

    void setVerified(bool verified);

private:
    Number* first;
    Number* middle;
    Number* last;

    bool signFirst;
    bool signMiddle;
    bool signLast;


    bool verified;

};


#endif //UNTITLED_CCLAUSE_H
