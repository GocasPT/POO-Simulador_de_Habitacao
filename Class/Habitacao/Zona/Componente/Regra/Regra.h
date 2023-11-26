#ifndef REGRA_H
#define REGRA_H


#include <vector>
#include "../Sensor/Sensor.h"
#include "../../Propriedade/Propriedade.h"

class Regra: public Componente {
    Sensor &sensor; // Sensor que a regra vai ler

public:
    Regra(int id);

    void readSensor(); // Lê o sensor
    bool validate(); // Valida a regra
};

#endif //REGRA_H