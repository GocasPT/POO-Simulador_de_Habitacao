#ifndef SENSOR_H
#define SENSOR_H

#include "../../Propriedade/Propriedade.h"
#include "../Componente.h"

using std::string;

class Sensor : public Componente {
protected:
    const string name; // Nome do sensor
    const char letter; // Letra do sensor
    const Propriedade &propriedade; // Propriedade que o sensor vai ler

public:
    Sensor(int id, string name, char letter, Propriedade &propriedade);

    string getName() const; // Getter do nome
    char getLetter() const; // Getter da letra

    int getPropriedadeValue() const; // Getter do valor da propriedade
};

#endif //SENSOR_H