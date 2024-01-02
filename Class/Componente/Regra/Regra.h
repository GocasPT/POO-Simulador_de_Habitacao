#ifndef REGRA_H
#define REGRA_H


#include <vector>
#include <iostream>
#include "../Sensor/Sensor.h"
#include "../../Propriedade/Propriedade.h"

enum class Operacao {
    IGUAL_A,
    MENOR_QUE,
    MAIOR_QUE,
    ENTRE,
    FORA,
    UNKNOWN,
};

class Regra : public Componente {
    const Sensor &sensor; // Sensor que a regra vai ler
    const Operacao operacao;
    const int x;
    const int y; // Valor adicional para regras "entre" e "fora"

public:
    Regra(int id, Operacao operacao, Sensor *sensor, int x, int y = 0);

    static Operacao stringToOperacao(const string &operacao);

    bool validate(); // Valida a regra

    string toString() const override;
};

#endif //REGRA_H