#include "SensorFactory.h"

#include "Sensores.h"

Sensor *SensorFactory::createSensor(TipoSensor tipo, int id, Zona &zona) {
    switch (tipo) {
        case TipoSensor::TEMPERATURA:
            return new SensorTemperatura(id, zona);

        case TipoSensor::MOVIMENTO:
            return new SensorMovimento(id, zona);

        case TipoSensor::LUMINOSIDADE:
            return new SensorLuminosidade(id, zona);

        case TipoSensor::RADIACAO:
            return new SensorRadiacao(id, zona);

        case TipoSensor::HUMIDADE:
            return new SensorHumidade(id, zona);

        case TipoSensor::SOM:
            return new SensorSom(id, zona);

        case TipoSensor::FUMO:
            return new SensorFumo(id, zona);
    }
}
