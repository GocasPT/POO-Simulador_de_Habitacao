#include <algorithm>
#include "Zona.h"

Zona::Zona(int id) : id(id) {
    idCounter = 0;
}

int Zona::getId() const { return id; }

std::map<std::string, Propriedade> Zona::getPropriedades() const { return propriedades; }

std::map<int, Componente> Zona::getComponentes() const { return componentes; }

Zona::~Zona() {

}