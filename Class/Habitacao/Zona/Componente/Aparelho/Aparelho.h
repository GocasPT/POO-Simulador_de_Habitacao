#ifndef POO_SIMULADOR_HABITACAO_APARELHO_H
#define POO_SIMULADOR_HABITACAO_APARELHO_H

#include <vector>
#include "../../Propriedade/Propriedade.h"

class Aparelho {
    int id;
    char letra;
    bool estado;
    std::vector<Propriedade> propriedades;

public:
    Aparelho();

    ~Aparelho();
};


#endif //POO_SIMULADOR_HABITACAO_APARELHO_H
