#include <sstream>
#include "Sensor.h"

using std::ostringstream;

Sensor::Sensor(int id, string name, char letter, Propriedade &propriedade) : Componente('s', id), name(name),
                                                                             letter(letter),
                                                                             propriedade(propriedade) {}

string Sensor::getName() const { return this->name; }

char Sensor::getLetter() const { return this->letter; }

int Sensor::getPropriedadeValue() const { return this->propriedade.getValue(); }

string Sensor::toString() const {
    ostringstream oss;

    oss << "Sensor de " << this->name << " (" << this->letter << ") - " << getId() << "\n";

    return oss.str();
}
