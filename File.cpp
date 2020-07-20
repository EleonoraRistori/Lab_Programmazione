//
// Created by eleonora on 14/07/20.
//

#include "File.h"

File::File(const char* fileName) {
    file = fopen(fileName, "rb");
    std::chrono::seconds dura( 2);
    std::this_thread::sleep_for( dura );
    if(!file){
        throw std::runtime_error("Cannot open file " + std::string(fileName));
    } else {
        fseek(file, 0, SEEK_END);
        fileSize = static_cast<int>(ftell(file));
    }
}

File::~File() {
    int control = fclose(file);
    if(control){
        throw std::runtime_error("Cannot close file!");
    }
}

int File::getFileSize() const {
    return fileSize;
}