#ifndef SENSORMOVIMENTO_H
#define SENSORMOVIMENTO_H


#include "../Sensor.h"
#include "../../../Zona/Zona.h"

class SensorMovimento : public Sensor {
public:
    SensorMovimento(int id, Zona &zona);
};


#endif //SENSORMOVIMENTO_H
