#ifndef FILE_HPP__
#define FILE_HPP__

#include <filesystem>
#include <iostream>
#include <cstdint>
#include <fstream>
#include <queue>

#include <time.h>

#include "util.hpp"

#define N 8

#define MAX 10

using namespace std;

namespace fs = std::filesystem;

class File {
private:
    const string _input;
    const string _resource;

    string _fileName;
    queue<int> _vecInput;

    void readThanCreate();
    void createMatriz();
    void removeThanCreate();
public:
    File(): _input("base/input.data"), _resource("base/resource") { }
    void createFile();
};

#endif