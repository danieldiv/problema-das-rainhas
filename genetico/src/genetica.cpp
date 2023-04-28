#include "include/genetica.hpp"

void Genetica::normalizarDados() {
    float aux;
    float controle = 0;
    float soma = 0;
    int individuo = 1;

    _intervalo.clear();

    for (const auto &[key, value] : _populacao) soma += value;

    for (const auto &[key, value] : _populacao) {
        aux = controle;
        controle += (value / soma);

        _intervalo.insert({ individuo++, make_pair(key,make_pair(aux,controle)) });
    }
}

void Genetica::genetic_algorithm() {
    normalizarDados();
    _populacao2.clear();

    int parent1;
    int parent2;

    for (int i = 0; i < MAX / 2; i++) {
        parent1 = weighted_random_choices();
        parent2 = weighted_random_choices();

        while (parent2 == parent1) parent2 = weighted_random_choices();

        auto childs = reproduce(_intervalo[parent1].first, _intervalo[parent2].first);

        setVariante2(childs.first);
        setVariante2(childs.second);
    }
    _populacao.clear();
    _populacao.insert(_populacao2.begin(), _populacao2.end());

    printPopulacao();
}

int  Genetica::weighted_random_choices() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 1);

    float num;

    for (int i = 0; i < MAX; i++) {
        num = dist(gen);

        for (const auto &[key, value] : _intervalo) {
            auto intervalo = value.second;

            if (intervalo.second >= num) return key;
        }
    }
    return 1;
}

pair<string, string> Genetica::reproduce(string &parent1, string &parent2) {
    size_t n = parent1.size();
    size_t c = (rand() % n);

    string child1;
    string child2;

    child1.append(parent1.substr(0, c + 1)).append(parent2.substr(c + 1, n));
    child2.append(parent2.substr(0, c + 1)).append(parent1.substr(c + 1, n));

    return make_pair(child1, child2);
}

pair<string, int> Genetica::getMax() {
    return Populacao::_max;
}