#include "Zona.h"
#include "Propriedade/Propriedades.h"

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

std::vector<Propriedade *> Zona::getPropriedades() const {
    std::vector < Propriedade * > vectorReturn;

    for (const auto &propriedade: propriedades)
        vectorReturn.push_back(propriedade.second);

    return vectorReturn;
}

std::vector <Componente> Zona::getComponentes() const {
    std::vector <Componente> vectorReturn;

    for (const auto &componente: componentes)
        vectorReturn.push_back(componente.second);

    return vectorReturn;
}

Propriedade *Zona::getPropriedade(const std::string &key) const {
    auto obj = propriedades.find(key);
    if (obj != propriedades.end())
        return obj->second;
    else
        return nullptr;
}

const Componente *Zona::getComponente(const std::string &id) const {
    auto obj = componentes.find(id);
    if (obj != componentes.end()) {
        return &obj->second;
    } else
        return nullptr;
}

//TODO [Meta 2]: funções para addicionar e remover componentes
bool Zona::addComponente(const std::string &id) {
    return false;
}

bool Zona::addComponente(const std::string &id, char type) {
    return false;
}

bool Zona::addComponente(const std::string &id, char type, char rule) {
    return false;
}

bool Zona::removeComponente(const std::string &id) {
    return false;
}

bool Zona::setPropriedade(const std::string &key, int value) {
    auto obj = propriedades.find(key);
    if (obj != propriedades.end()) {
        obj->second->setValor(value);
        return true;
    } else
        return false;
}

Zona::~Zona() {
    for (const auto &propriedade: propriedades)
        delete propriedade.second;
}