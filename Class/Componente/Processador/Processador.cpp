#include <algorithm>
#include <sstream>
#include "Processador.h"

using std::remove_if, std::ostringstream;

Processador::Processador(int id, string comando) : Componente('p', id) {
    this->comando = comando;
}

Processador Processador::clone() const {
    Processador clone(id, comando);
    return clone;
};

Processador &Processador::operator=(const Processador &processador) {
    if (this != &processador) {
        this->comando = processador.comando;
        this->regras = processador.regras;
        this->aparelhos = processador.aparelhos;
    }

    return *this;
}

vector<Regra *> Processador::getRegras() const {
    vector<Regra *> vectorReturn;

    for (const auto &regra: regras)
        vectorReturn.push_back(regra);

    return vectorReturn;
}

void Processador::addRegra(Regra *regra) { regras.push_back((Regra *const) regra); }

void Processador::removeRegra(const int id) {
    for (auto it = regras.begin(); it != regras.end(); ++it) {
        if ((*it)->getNumId() == id) {
            regras.erase(it);
            break;
        }
    }
}

void Processador::addAparelho(Aparelho *aparelho) { aparelhos.push_back(aparelho); }

void Processador::removeAparelho(const int id) {

}

void Processador::setComando(const string &command) { this->comando = command; }

bool Processador::validateRegras() {
    for(const auto regra: regras)
        if(!regra->validate()) return false;

    sendCommand();
    return true;
}

void Processador::sendCommand() {
    for(const auto aparelho: aparelhos)
        aparelho->readCommand(comando);
}

void Processador::update() { validateRegras(); }

string Processador::toString() const {
    ostringstream oss;

    oss << "Processador " << getId() << " - '" << comando << "'\n";
    for(const auto regra: regras)
        oss << regra->toString() << "\n";

    return oss.str();
}

Processador::~Processador() {
    for(const auto regra: regras)
        delete regra;
}
