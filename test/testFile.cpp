//
// Created by eleonora on 15/07/20.
//

#include "../File.h"
#include "gtest/gtest.h"

TEST(fileTest, testExistingFile){
    ASSERT_NO_THROW(File file("Text.txt"));
}

TEST(fileTest, testNonExistingFile){
    ASSERT_THROW(File file("Text3.txt"), std::runtime_error);
}