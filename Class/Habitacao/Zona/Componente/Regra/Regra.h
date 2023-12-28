#ifndef REGRA_H
#define REGRA_H


#include <vector>
#include <iostream>
#include "../Sensor/Sensor.h"
#include "../../Propriedade/Propriedade.h"

enum Operacao {
    igual_a,
    menor_que,
    maior_que,
    entre,
    fora };

class Regra : public Componente {
    Sensor &sensor; // Sensor que a regra vai ler
    Operacao operacao;
    int valor1;
    int valor2; // Valor adicional para regras "entre" e "fora"

public:
    Regra(int id);

    void readSensor(); // Lê o sensor
    bool validate(); // Valida a regra
};

#endif //REGRA_H