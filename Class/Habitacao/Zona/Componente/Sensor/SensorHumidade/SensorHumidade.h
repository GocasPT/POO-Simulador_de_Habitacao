#ifndef SENSORHUMIDADE_H
#define SENSORHUMIDADE_H


#include "../Sensor.h"
#include "../../../Zona.h"

class SensorHumidade : public Sensor {
public:
    SensorHumidade(int id, Zona &zona);
};


#endif //SENSORHUMIDADE_H
