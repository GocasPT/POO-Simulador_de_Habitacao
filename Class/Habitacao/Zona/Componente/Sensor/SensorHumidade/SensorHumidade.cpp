#include "SensorHumidade.h"

SensorHumidade::SensorHumidade(int id, Zona &zona) : Sensor(id, "humidade", 'h', *zona.getPropriedade(HUMIDADE_STR)) {}
