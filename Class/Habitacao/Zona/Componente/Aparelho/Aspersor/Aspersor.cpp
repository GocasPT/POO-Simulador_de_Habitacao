#include "Aspersor.h"

Aspersor::Aspersor(int id, Zona &zona) : Aparelho(id, 's', "aspersor") {
    propriedades[HUMIDADE_STR] = zona.getPropriedade(HUMIDADE_STR);
    propriedades[VIBRACAO_STR] = zona.getPropriedade(VIBRACAO_STR);
    propriedades[FUMO_STR] = zona.getPropriedade(FUMO_STR);
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