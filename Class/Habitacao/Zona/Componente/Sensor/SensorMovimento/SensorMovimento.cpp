#include "SensorMovimento.h"

SensorMovimento::SensorMovimento(int id, Zona &zona) : Sensor(id, "movimento", 'v',
                                                              *zona.getPropriedade(VIBRACAO_STR)) {}
