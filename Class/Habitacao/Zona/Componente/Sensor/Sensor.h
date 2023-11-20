#ifndef POO_SIMULADOR_HABITACAO_SENSOR_H
#define POO_SIMULADOR_HABITACAO_SENSOR_H

#include <string>
#include "../../Propriedade/Propriedade.h"
#include "../Componente.h"

class Sensor : public Componente {
    int id;
    char letter;
    //Propriedade &propriedade;

public:
    Sensor(int id, char letter);

    ~Sensor();
};


#endif //POO_SIMULADOR_HABITACAO_SENSOR_H
