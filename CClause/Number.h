//
// Created by Kamil on 21/01/2022.
//

#ifndef UNTITLED_NUMBER_H
#define UNTITLED_NUMBER_H

class Number {
public:
    Number(int nr) {
        this->nr = abs(nr);
    };

    int getNr() const {
        return nr;
    };

    void setState(bool state) {
        this->state = state;
    };

    bool getState() const {
        return state;
    }

    virtual ~Number() {

    }

private:
    int nr;
    bool state;
};

#endif //UNTITLED_NUMBER_H
