#ifndef GENETICA_HPP
#define GENETICA_HPP

#include "populacao.hpp"

class Genetica {
private:
    Populacao _populacao;
public:
    Genetica() { };

    Populacao &getPopulacao();
};

#endif