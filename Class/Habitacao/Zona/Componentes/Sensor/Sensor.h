#ifndef POO_SIMULADOR_HABITACAO_SENSOR_H
#define POO_SIMULADOR_HABITACAO_SENSOR_H

#include <string>

class Sensor {
    int id;
    char letra;
    std::string propriedade;

public:
    Sensor();

    ~Sensor();
};


#endif //POO_SIMULADOR_HABITACAO_SENSOR_H
