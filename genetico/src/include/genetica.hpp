#ifndef GENETICA_HPP
#define GENETICA_HPP

#include "populacao.hpp"

using type_intervalo = map<int, pair<string, pair<float, float>>>;

class Genetica: Populacao {
private:
    type_intervalo _intervalo;
public:
    Genetica() { };

    void normalizarDados();
    void genetic_algorithm();

    pair<string, string> reproduce(string &parent1, string &parent2);
    int weighted_random_choices();
    pair<string, int> getMax();
};

#endif