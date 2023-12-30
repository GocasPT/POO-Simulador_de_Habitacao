#include "Refrigerador.h"

Refrigerador::Refrigerador(int id, char letter, std::string name, std::map<string, Propriedade *> propriedades)
        : Aparelho(id, letter, name, propriedades){

}

void Refrigerador::ligar() {
    toggleState();
    // Adicionar 20 dB de ruído no primeiro instante de ligado
    // Remover um grau Celsius à temperatura da zona a cada 3 instantes ligado
    // Implemente a lógica conforme necessário
    std::cout << "Refrigerador ligado: a adicionar 20 dB de ruído." << std::endl;
}

void Refrigerador::desligar() {
    toggleState();
    // Remover 20 dB de ruído
    // Implemente a lógica conforme necessário
    std::cout << "Refrigerador desligado: a remover 20 dB de ruído." << std::endl;
}