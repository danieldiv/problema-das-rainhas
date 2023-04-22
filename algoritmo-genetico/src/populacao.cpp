#include "include/populacao.hpp"

void Populacao::setVariante(string key, int(&matriz)[N][N]) {
    int ataques = this->contAtaques(matriz);
    int porcentagem = ((_maximoAtaque - ataques) * 100) / _maximoAtaque;
    _populacao.insert({ key, porcentagem });
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

/**
 * @brief exibe a populacao ordenada pela melhor distribuicao das rainhas
 *
 */
type_order Populacao::orderPopulacao() {
    vector<std::pair<string, int>> arr;
    for (const auto &item : _populacao) {
        arr.emplace_back(item);
    }

    std::sort(arr.begin(), arr.end(),
        [](const auto &x, const auto &y) {return x.second > y.second; });

    return arr;
    // cout << endl;
    // for (const auto &[key, value] : arr) {
    //     cout << key << " " << value << endl;
    // }
}
