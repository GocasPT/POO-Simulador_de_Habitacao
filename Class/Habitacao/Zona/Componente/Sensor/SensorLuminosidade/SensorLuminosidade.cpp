#include "SensorLuminosidade.h"

SensorLuminosidade::SensorLuminosidade(int id, Zona &zona) : Sensor(id, "luminosidade", 'm',
                                                                    *zona.getPropriedade(LUZ_STR)) {}
