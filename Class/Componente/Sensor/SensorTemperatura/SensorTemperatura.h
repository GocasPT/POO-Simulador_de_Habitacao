#ifndef SENSORTEMPERATURA_H
#define SENSORTEMPERATURA_H


#include "../Sensor.h"
#include "../../../Zona/Zona.h"

class SensorTemperatura : public Sensor {
public:
    SensorTemperatura(int id, Zona &zona);
};


#endif //SENSORTEMPERATURA_H
