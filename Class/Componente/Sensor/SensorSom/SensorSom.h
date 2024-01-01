#ifndef SENSORSOM_H
#define SENSORSOM_H


#include "../../../Zona/Zona.h"
#include "../Sensor.h"

class SensorSom : public Sensor {
public:
    SensorSom(int id, Zona &zona);
};


#endif //SENSORSOM_H
