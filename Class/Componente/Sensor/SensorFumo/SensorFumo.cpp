#include "SensorFumo.h"

SensorFumo::SensorFumo(int id, Zona &zona) : Sensor(id, "fumo", 'f', *zona.getPropriedade(FUMO_STR)) {}
