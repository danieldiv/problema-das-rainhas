#ifndef FILE_HPP__
#define FILE_HPP__

#include <filesystem>
#include <iostream>
#include <cstdint>
#include <fstream>
#include <queue>

#include <time.h>

#include "util.hpp"
#include "populacao.hpp"

#define MAX 10

using namespace std;

namespace fs = std::filesystem;

class File {
private:
    const string _log;
    const string _input;
    const string _resource;

    string _fileName;
    queue<int> _vecInput;
    int _geracao;

    void readThanCreate(Populacao &p);
    void createMatriz(Populacao &p);
    void removeThanCreate();
public:
    File():
        _geracao(1),
        _log("base/logs/log.data"),
        _input("base/input.data"),
        _resource("base/resource") { }

    void createFile(Populacao &p);
    void createLog(type_order ordered);
    void printMatriz(int(&matriz)[N][N]);
};

#endif