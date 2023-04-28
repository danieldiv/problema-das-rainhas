#include "include/genetica.hpp"

Populacao &Genetica::getPopulacao() { return _populacao; }

void Genetica::genetic_algorithm() {
    auto myPopulation = _populacao.orderPopulacao();
    Populacao populacao2;

    bool aux = true;
    string parent1;
    string parent2;

    srand(time(nullptr));
    for (const auto &[key, value] : myPopulation) {
        if (aux) {
            aux = !aux;
            parent1.assign(key);
        } else {
            parent2.assign(key);
            aux = !aux;

            auto childs = reproduce(parent1, parent2);
            // populacao2.insert({ parent1,0 });
            // populacao2.insert({ parent2,0 });

            // populacao2.setInput;

            // _populacao.setPopulacao(populacao2);

            // cout << "[" << parent1 << " - " << parent2 << "]" << " -> ";
            // cout << "(" << childs.first << " - " << childs.second << ")" << endl;
        }
    }
}

void Genetica::calcProporcoes() {
    // proporcao de aptidao

    // Populacao p = getPopulacao();

    // int cont = 0;
    // for (const auto &[key, value] : this->getPopulacao()._populacao) {
    //     cout << key << " " << value << endl;
    //     cont += value;
    // }
    // cout << "som: " << cont << endl;

    // proporcao acumulada
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