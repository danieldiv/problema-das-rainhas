#ifndef GENETICA_HPP
#define GENETICA_HPP

#include "populacao.hpp"
#include <time.h>

class Genetica {
private:
    Populacao _populacao;
    Populacao _populacao2;
public:
    Genetica() { };

    Populacao &getPopulacao();
    void genetic_algorithm();
    void calcProporcoes();

    pair<string, string> reproduce(string &parent1, string &parent2);
};

#endif