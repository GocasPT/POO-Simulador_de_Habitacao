#include "SensorTemperatura.h"

SensorTemperatura::SensorTemperatura(int id, Zona &zona) : Sensor(id, "temperatura", 't',
                                                                  *zona.getPropriedade(TEMPERATURA_STR)) {}
