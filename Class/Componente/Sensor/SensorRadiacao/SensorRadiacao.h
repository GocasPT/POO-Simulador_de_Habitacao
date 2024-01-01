#ifndef SENSORRADIACAO_H
#define SENSORRADIACAO_H


#include "../Sensor.h"
#include "../../../Zona/Zona.h"

class SensorRadiacao : public Sensor {
public:
    SensorRadiacao(int id, Zona &zona);
};


#endif //SENSORRADIACAO_H
