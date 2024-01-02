#include "Aparelho.h"

#include <utility>
#include <sstream>
#include <cctype>

using std::map, std::ostringstream;

Aparelho::Aparelho(int id, char letter, string name)
        : Componente('a', id), letter(letter), name(std::move(name)) {}

string Aparelho::getName() const { return name; }

char Aparelho::getLetter() const { return letter; }

bool Aparelho::getState() const { return state; }

void Aparelho::readCommand(const string &command) {
    if (command == "ligar" && !state)
        ligar();
    else if (command == "desligar" && state)
        desligar();
}

void Aparelho::ligar() {
    state = true;
    letter = toupper(letter);
    instantCount = 0;
}

void Aparelho::desligar() {
    state = false;
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