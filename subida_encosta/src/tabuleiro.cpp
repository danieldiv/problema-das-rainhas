#include "include/tabuleiro.hpp"

void Tabuleiro::init() {
    _tab.clear();

    srand(time(nullptr));

    for (int i = 0; i < N; i++) {
        vector<int> coluna(N, 0);
        coluna.at(rand() % N) = 1;
        _tab.push_back(coluna);
    }

    for (const auto &coluna : _tab) {
        for (const auto &linha : coluna) cout << linha << " ";
        cout << endl;
    }
}