#include "SensorSom.h"

SensorSom::SensorSom(int id, Zona &zona) : Sensor(id, "som", 'o', *zona.getPropriedade(SOM_STR)) {}
