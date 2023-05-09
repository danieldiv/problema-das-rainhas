#ifndef TABULEIRO_HPP__
#define TABULEIRO_HPP__

#include <iostream>
#include <vector>
#include <time.h>

#define N 8

using namespace std;

class Tabuleiro {
protected:
    vector<vector<int>> _tab;
private:
public:
    Tabuleiro() { init(); }
    void init();
};

#endif