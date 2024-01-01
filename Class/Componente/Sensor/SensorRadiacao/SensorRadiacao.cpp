#include "SensorRadiacao.h"

SensorRadiacao::SensorRadiacao(int id, Zona &zona) : Sensor(id, "radiacao", 'd', *zona.getPropriedade(RADIACAO_STR)) {}
