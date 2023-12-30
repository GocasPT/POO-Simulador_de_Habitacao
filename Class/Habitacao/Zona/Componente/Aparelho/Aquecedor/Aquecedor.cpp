#include "Aquecedor.h"

using std::cout;
using std::endl;

Aquecedor::Aquecedor(int id, char letter, std::string name, std::map<string, Propriedade *> propriedades)
        : Aparelho(id, letter, name, propriedades){

}

void Aquecedor::ligar() {
    toggleState();
    instantCount++;
    if (instantCount % 3 == 0) {
        // Adicionar um grau Celsius à temperatura da zona
        // Verifique se a temperatura não ultrapassa 50º
        // Adicionar 5 dB de ruído uma única vez
        cout << "Aquecedor ligado: Adicionando um grau Celsius à temperatura." << endl;
        // Adicionar 5 dB de ruído
        // Implemente a lógica conforme necessário
    }
}

void Aquecedor::desligar() {
    toggleState();
    // Remover 5 dB de ruído
    // Implemente a lógica conforme necessário
    cout << "Aquecedor desligado: Removendo 5 dB de ruído." << endl;
}

