#ifndef POO_SIMULADOR_HABITACAO_PROCESSADOR_H
#define POO_SIMULADOR_HABITACAO_PROCESSADOR_H

#include <string>
#include <vector>
#include "Regra/Regra.h"

class Processador {
    int id;
    std::string comando;
    std::vector<Regra> regras;

public:
    Processador();

    ~Processador();
};


#endif //POO_SIMULADOR_HABITACAO_PROCESSADOR_H
