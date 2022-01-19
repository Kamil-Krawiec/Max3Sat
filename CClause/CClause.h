#ifndef UNTITLED_CCLAUSE_H
#define UNTITLED_CCLAUSE_H


class CClause {
public:
    CClause(int first, int middle, int last);

    bool bCheckClausule();

    void vSetNumber(int number, bool newState);

    bool isVerified() const;

    void setVerified(bool verified);

private:
    int first;
    int middle;
    int last;
    bool boolFirst;
    bool boolMiddle;
    bool boolLast;

    bool verified;

};


#endif //UNTITLED_CCLAUSE_H
