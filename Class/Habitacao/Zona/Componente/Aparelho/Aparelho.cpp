#include "Aparelho.h"

#include <utility>

using std::map;

Aparelho::Aparelho(int id, char letter, string name)
        : Componente('a', id), letter(letter), name(move(name)) {}

string Aparelho::getName() const { return name; }

char Aparelho::getLetter() const { return letter; }

bool Aparelho::getState() const { return state; }

void Aparelho::readCommand(const string &command) {

}

void Aparelho::toggleState() {
    state = !state;
}

void Aparelho::update() {

}

//TODO: toString
string Aparelho::toString() const {
    return Componente::toString();
}
