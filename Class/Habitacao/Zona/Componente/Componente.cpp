#include <sstream>
#include "Componente.h"

Componente::Componente(char c, int id): letterID(c), id(id) {}

int Componente::getId() const { return id; }
char Componente::getLetterID() const { return letterID; }
