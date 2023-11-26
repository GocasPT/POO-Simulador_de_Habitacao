#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <map>
#include <vector>
#include "Propriedade/Propriedade.h"
#include "Componente/Componente.h"

class Zona {
    const int id;
    int idCounter;
    std::map<std::string, Propriedade *> propriedades;
    std::map<std::string, Componente> componentes;

public:
    Zona(int id);

    int getId() const; // Getter do id
    std::vector<Propriedade *> getPropriedades() const; // Getter das propriedades
    std::vector<Componente> getComponentes() const; // Getter dos componentes
    const Propriedade * getPropriedade(const std::string& key) const; // Getter de uma propriedade
    const Componente * getComponente(const std::string& id) const; // Getter de um componente

    bool addComponente(const std::string &id); // Adiciona um componente Processador
    bool addComponente(const std::string &id, char type); // Adiciona um componente Sensor ou Aparlho
    bool addComponente(const std::string &id, char type, char rule); // Adiciona um componente Regra
    bool removeComponente(const std::string &id); // Remove um componente

    ~Zona();
};

#endif //ZONA_H