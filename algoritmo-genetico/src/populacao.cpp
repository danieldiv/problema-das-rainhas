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

void Populacao::cleanPopulacao() { _populacao.clear(); }

auto Populacao::getPopulacao() { return _populacao; }

void  Populacao::setPopulacao(Populacao &populacao2) {
    cleanPopulacao();
    _populacao.insert(populacao2.getPopulacao().begin(), populacao2.getPopulacao().end());
}

/**
 * @brief exibe a populacao ordenada pela melhor distribuicao das rainhas
 *
 */
type_order Populacao::orderPopulacao() {
    cout << endl;

    vector<std::pair<string, int>> arr;
    for (const auto &item : _populacao)
        arr.emplace_back(item);

    std::sort(arr.begin(), arr.end(),
        [](const auto &x, const auto &y) {return x.second > y.second; });


    float cont = 0;
    for (const auto &[key, value] : _populacao) {
        cout << key << " " << value << endl;
        cont += value;
    }
    cout << "som: " << cont << endl << endl;

    map<int, pair<string, pair<float, float>>> intervalo;
    int individuo = 1;

    std::fixed(std::cout);
    for (const auto &[key, value] : _populacao) {
        cout << key << " " << setprecision(3) << value / cont << endl;
    }

    float controle = 0;
    float aux;
    cout << endl;

    for (const auto &[key, value] : _populacao) {
        aux = controle;
        controle += (value / cont);

        intervalo.insert({ individuo++, make_pair(key,make_pair(aux,controle)) });
        // cout << key << " [ " << setprecision(3) << aux << " - " << setprecision(3) << controle << " ]" << endl;
    }

    cout << endl;
    for (const auto &[key, value] : intervalo) {
        auto intervalo = value.second;
        cout << key << " - " << value.first << " [ " << setprecision(3) << intervalo.first << " - " << setprecision(3) << intervalo.second << " ]" << endl;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 1);

    cout << endl;
    for (int i = 0; i < N; i++) {
        std::cout << dist(gen) << std::endl;
    }

    return arr;
}
