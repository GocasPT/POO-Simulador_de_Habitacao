#include "Zona.h"
#include "Propriedade/Propriedades.h"

using std::cout;
using std::endl;

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

vector<Propriedade *> Zona::getPropriedades() const {
    vector < Propriedade * > vectorReturn;

    for (const auto &propriedade: propriedades)
        vectorReturn.push_back(propriedade.second);

    return vectorReturn;
}

vector <Componente> Zona::getComponentes() const {
    vector <Componente> vectorReturn;

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

const Componente *Zona::getComponente(const string &id) const {
    auto obj = componentes.find(id);
    if (obj != componentes.end()) {
        return &obj->second;
    } else
        return nullptr;
}

//TODO [Meta 2]: funções para addicionar e remover componentes
bool Zona::addComponente(const string &id) {
    //return false;

    // Verifica se o componente já existe
    if (componentes.find(id) != componentes.end()) {
        cout << "Erro: Componente com ID " << id << " já existe na zona." << endl;
        return false;
    }

    // Cria e adiciona o componente (um Processador)
   // Processador processador(id);
     //componentes[id] = processador;

    cout << "Componente com ID " << id << " adicionado com sucesso." << endl;
    return true;
}

bool Zona::addComponente(const string &id, char type) {
    //Sensor e aparelho
    if (componentes.find(id) != componentes.end()) {
        cout << "Erro: Componente com ID " << id << " já existe na zona." << endl;
        return false;
    }

    // Cria e adiciona o componente (um aparelho)
    //Aparelho aparelho(id);
    //componentes[id] = aparelho;

    // Cria e adiciona o componente (um sensor)
    //Sensor sensor(id);
    //componentes[id] = sensor;

    cout << "Componente com ID " << id << " adicionado com sucesso." << endl;

    return false;
}

bool Zona::addComponente(const string &id, char type, char rule) {
    //regra
    if (componentes.find(id) != componentes.end()) {
        std::cout << "Erro: Componente com ID " << id << " já existe na zona." << std::endl;
        return false;
    }

    // Cria e adiciona o componente (uma regra)
    //Regra regra(id);
    //componentes[id] = regra;

    cout << "Componente com ID " << id << " adicionado com sucesso." << endl;


    return false;
}

bool Zona::removeComponente(const string &id) {
    auto it = componentes.find(id);

    // Verifica se o componente existe
    if (it != componentes.end()) {
        // Remove o componente
        componentes.erase(it);

        cout << "Componente com ID " << id << " removido com sucesso." << endl;
        return true;
    } else {
        cout << "Erro: Componente com ID " << id << " não encontrado na zona." << endl;
        return false;
    }
}

bool Zona::setPropriedade(const string &key, int value) {
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