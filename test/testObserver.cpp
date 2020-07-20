//
// Created by eleonora on 20/07/20.
//

#include "testObserver.h"


testObserver::testObserver(FileLoader *s) : subject(s) {
    attach();
}

testObserver::~testObserver() {
    detach();
}

void testObserver::attach() {
    subject -> addObserver(this);
}

void testObserver::detach() {
    subject -> removeObserver(this);
}

void testObserver::startLoadingFiles() {
    std::list <std::string> files;
    files.emplace_back("Text.txt");
    files.emplace_back("Text2.txt");
    files.emplace_back("Image.svg");
    subject->loadFiles(files);
}

void testObserver::update() {
    std::string fileName = subject->getFileName().toUtf8().constData();
    if(subject->isLoaded1()){
        std::cout << "File " << fileName << " loaded\n";
    } else
        throw std::runtime_error("Impossible to open "+ fileName);
}

