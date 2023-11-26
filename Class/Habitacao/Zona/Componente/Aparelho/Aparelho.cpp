#include "Aparelho.h"

#include <utility>

Aparelho::Aparelho(int id, char letter, std::string name, std::map<std::string, Propriedade *> propriedades) : Componente('a', id), letter(letter), name(std::move(name)) {
    //TODO: aparelho recebe propriedades (referencia ou ponteiro) [PROPRIEDADES EXISTE FORA DA CLASSE]
    //this->propriedades = propriedades;
}

std::string Aparelho::getName() const { return name; }

char Aparelho::getLetter() const { return letter; }

bool Aparelho::getState() const { return state; }

void Aparelho::readCommand(const std::string &command) {

}

void Aparelho::toggleState() {
    state = !state;
}

void Aparelho::update() {

}
