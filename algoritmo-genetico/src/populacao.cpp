#include "include/populacao.hpp"

void Populacao::setVariante(string key, int(&matriz)[N][N]) {
    int ataques = this->contAtaques(matriz);
    int maximoAtaque = (N * (N + 1)) / 2;
    // (N*(N+1))/2
    _populacao.insert({ key,make_pair(ataques, maximoAtaque) });
}

void Populacao::setInput(int val) { _input.push(val); }

int Populacao::contAtaques(int(&matriz)[N][N]) {
    int ataque = 0;
    int col_direita = 0;
    int col_sup_direita = 0;
    int col_inf_direita = 0;
    int col;

    int linha_copia;

    while (!_input.empty()) {
        int linha = _input.front();
        linha = N - linha;

        for (col = ++col_direita; col < N; col++) {
            if (matriz[linha][col] == 1) ataque++;
        }

        col = col_sup_direita++;
        linha_copia = linha;
        while (--linha_copia >= 0 && ++col < N) {
            if (matriz[linha_copia][col] == 1) ataque++;
        }

        col = col_inf_direita++;
        linha_copia = linha;
        while (++linha_copia < N && ++col < N) {
            if (matriz[linha_copia][col] == 1) ataque++;
        }
        _input.pop();
    }
    return ataque;
}

void Populacao::showPopulacao() {
    cout << endl;
    for (auto it = _populacao.begin(); it != _populacao.end(); ++it) {
        // cout << it->first << " " << it->second << endl;
    }
}
