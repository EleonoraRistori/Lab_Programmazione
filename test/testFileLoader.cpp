//
// Created by eleonora on 15/07/20.
//

#include "../FileLoader.h"
#include "gtest/gtest.h"

TEST(fileLoaderTest, testListOfFiles){
    FileLoader loader;
    std::list<const char*> files;
    files.push_back("Text.txt");
    files.push_back("Text2.txt");
    files.push_back("Image.svg");
    ASSERT_NO_THROW(loader.loadFiles(files));
}

TEST(fileLoaderTest, testEmptyListOfFiles){
    FileLoader* loader;
    std::list<const char*> files;
    ASSERT_THROW(loader->loadFiles(files), std::runtime_error);
}

