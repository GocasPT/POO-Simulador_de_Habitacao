#include "Aparelho.h"

#include <utility>
#include <sstream>

using std::map, std::ostringstream;

Aparelho::Aparelho(int id, char letter, string name)
        : Componente('a', id), letter(letter), name(std::move(name)) {}

string Aparelho::getName() const { return name; }

char Aparelho::getLetter() const { return letter; }

bool Aparelho::getState() const { return state; }

void Aparelho::toggleState() {
    state = !state;
    if (state)
        letter = toupper(letter);
    else
        letter = tolower(letter);
    instantCount = 0;
}

string Aparelho::toString() const {
    ostringstream oss;

    oss << "Aparelho: " << name
        << "Id:" << getId()
        << "Estado: " << state
        << '\n';

    return oss.str();
}
