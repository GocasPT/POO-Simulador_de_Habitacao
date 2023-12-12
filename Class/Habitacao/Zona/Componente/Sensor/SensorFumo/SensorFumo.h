#ifndef SENSORFUMO_H
#define SENSORFUMO_H


#include "../Sensor.h"
#include "../../../Zona.h"

class SensorFumo : public Sensor {
public:
    SensorFumo(int id, Zona &zona);
};


#endif //SENSORFUMO_H
