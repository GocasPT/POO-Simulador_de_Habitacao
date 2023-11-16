//
// Created by Guilherme Camacho on 09/11/2023.
//

#ifndef POO_SIMULADOR_HABITACAO_REGRA_H
#define POO_SIMULADOR_HABITACAO_REGRA_H


#include <vector>
#include "../../Sensor/Sensor.h"
#include "../../../Propriedade/Propriedade.h"

class Regra {
    Sensor &sensor;
    std::vector<Propriedade> propriedades;

public:
    Regra(Sensor &sensor);

    ~Regra();
};


#endif //POO_SIMULADOR_HABITACAO_REGRA_H
