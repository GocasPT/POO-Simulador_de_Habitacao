#include <sstream>
#include "Componente.h"

using std::ostringstream;

Componente::Componente(char c, int id) : letterID(c), id(id) {}

string Componente::getId() const {
    ostringstream os;

    os << letterID << id;

    return os.str();
}

int Componente::getNumId() const { return id; }

char Componente::getLetterID() const { return letterID; }

string Componente::toString() const {
    ostringstream oss;

    oss << "Id: " << getId() << '\n';

    return oss.str();
}
