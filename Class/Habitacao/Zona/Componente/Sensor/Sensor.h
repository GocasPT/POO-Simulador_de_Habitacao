#ifndef SENSOR_H
#define SENSOR_H

#include "../../Propriedade/Propriedade.h"
#include "../Componente.h"

class Sensor: public Componente {
    const std::string name; // Nome do sensor
    const char letter; // Letra do sensor
    Propriedade &propriedade; // Propriedade que o sensor vai ler

public:
    Sensor(int id, std::string name, int idZona, std::string propriedadeKey);

    std::string getName() const; // Getter do nome
    char getLetter() const; // Getter da letra

    int getPropriedadeValue() const; // Getter do valor da propriedade
};

#endif //SENSOR_H