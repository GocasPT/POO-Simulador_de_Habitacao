#include "Componente.h"

Componente::Componente(int id, ComponentType type) {
    this->id = id;
    this->type = type;
}

int Componente::getId() const { return id; }

ComponentType Componente::getType() const { return type; }

Componente::~Componente() {

}
