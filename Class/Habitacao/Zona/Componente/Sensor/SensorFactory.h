#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include "Sensor.h"
#include "../../Zona.h"

enum class TipoSensor {
    TEMPERATURA,
    MOVIMENTO,
    LUMINOSIDADE,
    RADIACAO,
    HUMIDADE,
    SOM,
    FUMO,
    UNKNOWN,
};

class SensorFactory {
public:
    static TipoSensor stringToTipoSensor(const string &tipo);
    static Sensor *createSensor(TipoSensor tipo, int id, Zona &zona);
};


#endif //SENSORFACTORY_H
