//
// Created by eleonora on 14/07/20.
//

#ifndef LAB_PROGRAMMAZIONE_VIEW_H
#define LAB_PROGRAMMAZIONE_VIEW_H


#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QString>
#include <QLabel>
#include <QErrorMessage>
#include "Observer.h"
#include "FileLoader.h"

class View : public QMainWindow, public Observer {
Q_OBJECT
public:
    explicit View(FileLoader* s);

    virtual ~View();

    void attach() override;
    void detach() override;
    void update() override;

private slots:
    void startLoadingFiles();

private:
    FileLoader* subject;
    QPushButton* button;
    QProgressBar* progressBar;
    QLabel* label;
    QErrorMessage* errorMessage;

};



#endif //LAB_PROGRAMMAZIONE_VIEW_H
