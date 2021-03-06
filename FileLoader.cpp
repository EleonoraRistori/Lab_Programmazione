//
// Created by eleonora on 14/07/20.
//

#include "FileLoader.h"

void FileLoader::addObserver(Observer *o) {
    observers.push_back(o);
}

void FileLoader::removeObserver(Observer *o) {
    observers.remove(o);
}

void FileLoader::notify() {
    for(auto observer : observers)
        observer->update();
}

void FileLoader::loadFiles(std::list<std::string> &fileNames) {
    numFiles = fileNames.size();
    if (numFiles == 0){
        throw std::runtime_error("No files found");
    }
    else {
        for (auto fileName : fileNames)
            handleFile(fileName);
    }


}

void FileLoader::handleFile(std::string fileName) {
    this->fileName = QString::fromStdString(fileName);;
    try {
        File file(fileName.c_str());
        isLoaded = true;
        notify();
    } catch (std::runtime_error& e){
        std::cerr << e.what() << std::endl;
        isLoaded = false;
        notify();
    }
}


int FileLoader::getNumFiles() const {
    return numFiles;
}

bool FileLoader::isLoaded1() const {
    return isLoaded;
}

const QString &FileLoader::getFileName() const {
    return fileName;
}


