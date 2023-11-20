#include "Sensor.h"

Sensor::Sensor(int id, char letter) : Componente(id, SENSOR) {
    this->id = id;
    this->letter = letter;
}

Sensor::~Sensor() {

}
