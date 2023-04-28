#include "include/populacao.hpp"

void Populacao::initPopulacao() {
    // cout << "Criando populacao aleatoria de tamanho " << MAX << " com " << N << " individuos" << endl;
    srand(time(nullptr));

    int cont = 0;
    int col = 0;
    int val;

    while (cont++ < MAX) {
        string gene("");
        int matriz[N][N] = { 0 };
        col = 0;

        for (int j = 0; j < N; j++) {
            val = (1 + rand() % N);

            setInput(val);
            gene.append(to_string(val));
            matriz[N - val][col++] = 1;
        }
        setVariante(gene, matriz);
    }
}

void Populacao::setVariante(string key, int(&matriz)[N][N]) {
    int ataques = this->contAtaques(matriz);
    int porcentagem = ((_maximoAtaque - ataques) * 100) / _maximoAtaque;
    _populacao.insert({ key, porcentagem });
}

void Populacao::setVariante2(string key) {
    int val;
    int col = 0;
    int matriz[N][N] = { 0 };

    for (const auto &num : key) {
        val = num - '0';
        _input.push(val);
        matriz[N - val][col++] = 1;
    }
    int ataques = this->contAtaques(matriz);
    int porcentagem = ((_maximoAtaque - ataques) * 100) / _maximoAtaque;
    _populacao2.insert({ key, porcentagem });
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

type_order Populacao::orderPopulacao() {
    vector<std::pair<string, int>> arr;
    for (const auto &item : _populacao)
        arr.emplace_back(item);

    std::sort(arr.begin(), arr.end(),
        [](const auto &x, const auto &y) {return x.second > y.second; });

    return arr;
}

void Populacao::printPopulacao() {
    for (const auto &[key, value] : orderPopulacao()) {
        if (value > _max.second) {
            _max.first = key;
            _max.second = value;
        }
        break;
    }
}