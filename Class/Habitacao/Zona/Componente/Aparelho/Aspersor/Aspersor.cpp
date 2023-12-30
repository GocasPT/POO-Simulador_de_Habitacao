#include "Aspersor.h"

Aspersor::Aspersor(int id, char letter, std::string name, std::map<string, Propriedade *> propriedades)
         : Aparelho(id, letter, name, propriedades) {

}

void Aspersor::ligar() {
    toggleState();

    // No primeiro instante de ligado:
    // Adicionar 50% de humidade relativa, até ao máximo de 75% de humidade
    // Adicionar vibração de 100 Hz
    // Colocar o fumo a 0 uma única vez no segundo instante
    // Implemente a lógica conforme necessário
    std::cout << "Aspersor ligado: A adicionar 50% de humidade relativa." << std::endl;
    std::cout << "A adicionar vibração de 100 Hz." << std::endl;
}

void Aspersor::desligar() {
    toggleState();
    // Remover 100 Hz de vibração
    // Implemente a lógica conforme necessário
    std::cout << "Aspersor desligado: a removendo 100 Hz de vibração." << std::endl;

}