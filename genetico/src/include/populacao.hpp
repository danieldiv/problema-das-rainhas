#ifndef POPULACAO_HPP__
#define POPULACAO_HPP__

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <string>
#include <queue>
#include <map>

#include <thread>

#define N 8
#define MAX 500

using namespace std;

using type_populacao = unordered_map<string, int>;
using type_order = vector<std::pair<string, int>>;

class Populacao {
protected: // pode ser usado pela classe que herda
    type_populacao _populacao;
    type_populacao _populacao2;
    pair<string, int> _max;
private: // so a classe populacao tem acesso
    int _maximoAtaque;
    queue<int> _input;
public:
    Populacao() : _maximoAtaque(((N - 1) *N) / 2) { initPopulacao(); }

    void initPopulacao();
    void setInput(int val);
    void setVariante(string key, int(&matriz)[N][N]);
    void setVariante2(string key);

    int contAtaques(int(&matriz)[N][N]);
    void obterMaior();
    type_order orderPopulacao();
};

#endif