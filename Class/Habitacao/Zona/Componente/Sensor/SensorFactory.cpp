#include "SensorFactory.h"

#include "Sensores.h"

using std::map;

TipoSensor SensorFactory::stringToTipoSensor(const string &tipo) {
    static const map<string, TipoSensor> tipoSensorMap = {
            {"Temperatura", TipoSensor::TEMPERATURA},
            {"Movimento",   TipoSensor::MOVIMENTO},
            {"Luminosidade",TipoSensor::LUMINOSIDADE},
            {"Radiacao",    TipoSensor::RADIACAO},
            {"Humidade",    TipoSensor::HUMIDADE},
            {"Som",         TipoSensor::SOM},
            {"Fumo",        TipoSensor::FUMO},
    };

    auto it =  tipoSensorMap.find(tipo);
    if (it != tipoSensorMap.end()) {
        return it->second;
    }

    return TipoSensor::UNKNOWN;
}

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
        default:
            return nullptr;
    }
}
