//
// Created by eleonora on 14/07/20.
//

#ifndef LAB_PROGRAMMAZIONE_FILE_H
#define LAB_PROGRAMMAZIONE_FILE_H

#include <string>
#include <stdexcept>

class File {
    public:
        File(const char* fileName);
        ~File();

        int getFileSize() const;

    private:
        FILE* file;
        int fileSize;
};


#endif //LAB_PROGRAMMAZIONE_FILE_H
