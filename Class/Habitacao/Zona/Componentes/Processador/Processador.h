#ifndef POO_SIMULADOR_HABITACAO_PROCESSADOR_H
#define POO_SIMULADOR_HABITACAO_PROCESSADOR_H

#include <string>
#include <vector>
#include "Regra/Regra.h"

class Processador {
private:
    int id;
    std::string comando;
    std::vector<Regra*> regras;
public:

};


#endif //POO_SIMULADOR_HABITACAO_PROCESSADOR_H
