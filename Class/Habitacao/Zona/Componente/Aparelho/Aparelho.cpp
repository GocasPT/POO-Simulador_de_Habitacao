#include "Aparelho.h"

#include <utility>

Aparelho::Aparelho(int id, char letter, string name, std::map<string, Propriedade *> propriedades)
        : Componente('a', id), letter(letter), name(std::move(name)) {
    //TODO: aparelho recebe propriedades (referencia ou ponteiro) [PROPRIEDADES EXISTE FORA DA CLASSE]
    //this->propriedades = propriedades;
}

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
