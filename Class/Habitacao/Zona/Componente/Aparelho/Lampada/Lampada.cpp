#include "Lampada.h"

Lampada::Lampada(int id, char letter, std::string name, std::map<string, Propriedade *> propriedades)
        : Aparelho(id, letter, name, propriedades){

}

void Lampada::ligar() {
    toggleState();
    // Adicionar 900 lúmens uma única vez por período em que está ligado
    // Implemente a lógica conforme necessário
    std::cout << "Lampada ligada: a adicionar 900 lúmens." << std::endl;
}


void Lampada::desligar() {
    toggleState();
    // Remover 900 lúmens
    // Implemente a lógica conforme necessário
    std::cout << "Lampada desligada: a remover 900 lúmens." << std::endl;

}