//
// Created by eleonora on 14/07/20.
//

#ifndef LAB_PROGRAMMAZIONE_OBSERVER_H
#define LAB_PROGRAMMAZIONE_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;
};

#endif //LAB_PROGRAMMAZIONE_OBSERVER_H
