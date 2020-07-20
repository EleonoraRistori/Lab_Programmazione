//
// Created by eleonora on 20/07/20.
//

#ifndef LAB_PROGRAMMAZIONE_TESTOBSERVER_H
#define LAB_PROGRAMMAZIONE_TESTOBSERVER_H
#include "../Observer.h"
#include "../FileLoader.h"

class testObserver : public Observer{
public:
    explicit testObserver(FileLoader* s);
    virtual ~testObserver();

    void attach() override;
    void detach() override;
    void update() override;

    void startLoadingFiles();

private:
    FileLoader* subject;

};


#endif //LAB_PROGRAMMAZIONE_TESTOBSERVER_H
