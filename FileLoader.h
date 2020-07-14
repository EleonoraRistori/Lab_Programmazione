//
// Created by eleonora on 14/07/20.
//

#ifndef LAB_PROGRAMMAZIONE_FILELOADER_H
#define LAB_PROGRAMMAZIONE_FILELOADER_H

#include <list>
#include <iostream>
#include "Subject.h"
#include "File.h"

class FileLoader : public Subject {
public:
    FileLoader() : numFiles(0) {}

    void loadFiles(std::list<const char*>& fileNames);
    void handleFile(const char* fileName);


    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

private:
    std::list<Observer*> observers;
    int numFiles;

};


#endif //LAB_PROGRAMMAZIONE_FILELOADER_H
