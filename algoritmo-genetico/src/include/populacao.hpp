#ifndef POPULACAO_HPP__
#define POPULACAO_HPP__

#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define N 8

using namespace std;

// using type_populacao = unordered_map<string, int>;
using type_populacao = unordered_map<string, pair<int, int>>;

class Populacao {
private:
    type_populacao _populacao;
    queue<int> _input;
public:
    Populacao() { }

    int contAtaques(int(&matriz)[N][N]);

    void setInput(int val);
    void setVariante(string key, int(&matriz)[N][N]);
    void showPopulacao();
};

#endif