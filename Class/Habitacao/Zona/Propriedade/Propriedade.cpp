#include "Propriedade.h"

Propriedade::Propriedade(std::string name, int value) {
    this->name = name;
    this->value = value;
}


std::string Propriedade::getName() const { return name; }

int Propriedade::getValue() const { return value; }

void Propriedade::setValor(int valor) { this->value = valor; }

Propriedade::~Propriedade() {

}