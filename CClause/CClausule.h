//
// Created by Kamil on 18/01/2022.
//

#ifndef UNTITLED_CCLAUSULE_H
#define UNTITLED_CCLAUSULE_H


class CClausule {
public:
    CClausule(int first, int middle, int last);

    bool bCheckClausule();

    bool bSetClausule(bool first, bool middle, bool last);

private:
    int first;
    int middle;
    int last;
    bool boolFirst;
    bool boolMiddle;
    bool boolLast;

};


#endif //UNTITLED_CCLAUSULE_H
