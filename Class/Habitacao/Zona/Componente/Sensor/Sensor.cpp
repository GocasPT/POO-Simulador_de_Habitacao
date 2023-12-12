#include "Sensor.h"

Sensor::Sensor(int id, std::string name, char letter, Propriedade &propriedade) : Componente('s', id), name(name),
                                                                                  letter(letter),
                                                                                  propriedade(propriedade) {}

std::string Sensor::getName() const { return this->name; }

char Sensor::getLetter() const { return this->letter; }

int Sensor::getPropriedadeValue() const { return this->propriedade.getValue(); }
