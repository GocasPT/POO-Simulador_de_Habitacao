#ifndef SENSORLUMINOSIDADE_H
#define SENSORLUMINOSIDADE_H


#include "../Sensor.h"
#include "../../../Zona.h"

class SensorLuminosidade : public Sensor {
public:
    SensorLuminosidade(int id, Zona &zona);
};


#endif //SENSORLUMINOSIDADE_H
