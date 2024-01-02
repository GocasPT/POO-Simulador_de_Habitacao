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
    letter = (char) toupper(letter);
    instantCount = 0;
}

void Aparelho::desligar() {
    state = false;
    letter = (char) tolower(letter);
    instantCount = 0;
}

string Aparelho::toString() const {
    ostringstream oss;

    oss << "Aparelho: " << name << " "
        << "Id:" << getId() << " "
        << "Estado: " << ( state ? "Ligado" : "Desligado" )
        << '\n';

    return oss.str();
}

string Aparelho::getId() const {
    ostringstream oss;

    oss << getLetterID() << letter << getNumId();

    return oss.str();
}
