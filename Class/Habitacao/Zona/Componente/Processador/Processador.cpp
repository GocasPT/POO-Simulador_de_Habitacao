#include "Processador.h"

Processador::Processador(int id, string comando) : Componente( 'p', id){
    this->comando = comando;
}

void Processador::addRegra(Regra &regra) { regras.push_back(regra); }

void Processador::addAparelho(Aparelho *aparelho) { aparelhos.push_back(aparelho); }

void Processador::setComando(const string &command) { this->comando = command; }

bool Processador::validateRegras() {
    return true;
}

void Processador::sendCommand() {

}

Processador::~Processador() {

}
