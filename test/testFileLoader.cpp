//
// Created by eleonora on 15/07/20.
//

#include "../FileLoader.h"
#include "../test/testObserver.h"
#include "gtest/gtest.h"

TEST(fileLoaderTest, testListOfFiles){
    FileLoader loader;
    std::list<std::string> files;
    files.emplace_back("Text.txt");
    files.emplace_back("Text2.txt");
    files.emplace_back("Image.svg");
    ASSERT_NO_THROW(loader.loadFiles(files));
}

TEST(fileLoaderTest, testEmptyListOfFiles){
    FileLoader loader;
    std::list<std::string> files;
    ASSERT_THROW(loader.loadFiles(files), std::runtime_error);
}

TEST(fileLoaderTest, testLoading){
    FileLoader loader;
    loader.handleFile("Text.txt");
    ASSERT_EQ(loader.isLoaded1(), true);
}

TEST(fileLoaderTest, testFailedLoading){
    FileLoader loader;
    loader.handleFile("Text3.txt");
    ASSERT_EQ(loader.isLoaded1(), false);
}

TEST(fileLoaderTest, testUpdate){
    FileLoader loader;
    testObserver observer(&loader);
    ASSERT_NO_THROW(observer.startLoadingFiles());
}