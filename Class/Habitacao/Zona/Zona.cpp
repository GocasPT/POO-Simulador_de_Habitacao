#include <sstream>
#include "Zona.h"
#include "Propriedade/Propriedades.h"
#include "Componente/Sensor/Sensor.h"

Zona::Zona(int id) : id(id) {
    idCounter = 0;

    // Criação das propriedades de ambiente e adição ao map
    propriedades[TEMPERATURA_STR] = new Temperatura();
    propriedades[LUZ_STR] = new Luz();
    propriedades[RADIACAO_STR] = new Radiacao();
    propriedades[VIBRACAO_STR] = new Vibracao();
    propriedades[HUMIDADE_STR] = new Humidade();
    propriedades[FUMO_STR] = new Fumo();
    propriedades[SOM_STR] = new Som();
}

int Zona::getId() const { return id; }

int Zona::getIdCounter() const { return idCounter; }

vector<Propriedade *> Zona::getPropriedades() const {
    vector < Propriedade * > vectorReturn;

    for (const auto &propriedade: propriedades)
        vectorReturn.push_back(propriedade.second);

    return vectorReturn;
}

vector <Componente*> Zona::getComponentes() const {
    vector <Componente*> vectorReturn;

    for (const auto &componente: componentes)
        vectorReturn.push_back(componente.second);

    return vectorReturn;
}

Propriedade *Zona::getPropriedade(const string &key) const {
    auto obj = propriedades.find(key);
    if (obj != propriedades.end())
        return obj->second;
    else
        return nullptr;
}

const Componente *Zona::getComponente(const int id) const {
    auto obj = componentes.find(id);
    if (obj != componentes.end()) {
        return obj->second;
    } else
        return nullptr;
}

bool Zona::addComponente(Aparelho *aparelho) {
    if (!aparelho) return false;
    componentes[aparelho->getNumId()] = aparelho;
    idCounter++;
    return true;
}

bool Zona::addComponente(Processador *processador) {
    if (!processador) return false;
    componentes[processador->getNumId()] = processador;
    idCounter++;
    return true;
}

bool Zona::addComponente(Sensor *sensor) {
    if (!sensor) return false;
    componentes[sensor->getNumId()] = sensor;
    idCounter++;
    return true;
}

bool Zona::removeComponente(char tipoComponente, const int id) {
    auto it = componentes.find(id);

    if (it != componentes.end()) {
        Componente* obj = it->second;
        if (obj->getLetterID() == tipoComponente) {
            componentes.erase(it);
            return true;
        }
    }

    return false;
}

bool Zona::setPropriedade(const string &key, int value) {
    auto obj = propriedades.find(key);
    if (obj != propriedades.end()) {
        obj->second->setValor(value);
        return true;
    } else
        return false;
}

//TODO: toString
string Zona::toString() const {
    return std::string();
}

Zona::~Zona() {
    for (const auto &propriedade: propriedades)
        delete propriedade.second;

    for (const auto &componente: componentes)
        delete componente.second;
}
