#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <map>
#include "Propriedade/Propriedade.h"
#include "Componente/Componente.h"

class Zona {
    const int id;
    int idCounter;
    std::map<std::string, Propriedade> propriedades;
    std::map<int, Componente> componentes;

public:
    Zona(int id);

    int getId() const; // Getter do id
    std::map<std::string, Propriedade> getPropriedades() const; // Getter das propriedades
    std::map<int, Componente> getComponentes() const; // Getter dos componentes


    //TODO: Verificar esta parte
    void addPropriedade(const std::string &name, const std::string &value); // Adiciona uma propriedade
    void addComponente(const std::string &name,
                       const std::string &description); // Adiciona um componente

    ~Zona();
};


#endif //ZONA_H
