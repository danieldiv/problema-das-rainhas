#ifndef POPULACAO_HPP__
#define POPULACAO_HPP__

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define N 8

using namespace std;

using type_populacao = unordered_map<string, int>;
using type_order = vector<std::pair<string, int>>;

class Populacao {
private:
    type_populacao _populacao;
    queue<int> _input;
    int _maximoAtaque;
public:
    Populacao(): _maximoAtaque(((N - 1) *N) / 2) { }

    int contAtaques(int(&matriz)[N][N]);

    void setInput(int val);
    void setVariante(string key, int(&matriz)[N][N]);
    type_order orderPopulacao();
};

#endif