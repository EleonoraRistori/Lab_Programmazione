//
// Created by eleonora on 14/07/20.
//

#ifndef LAB_PROGRAMMAZIONE_SUBJECT_H
#define LAB_PROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"

class Subject{
public:
    virtual ~Subject() {}
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notify() = 0;
};

#endif //LAB_PROGRAMMAZIONE_SUBJECT_H
