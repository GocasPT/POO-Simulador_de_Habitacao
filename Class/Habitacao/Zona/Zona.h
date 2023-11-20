#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <map>
#include "Propriedade/Propriedade.h"
#include "Componente/Processador/Processador.h"
#include "Componente/Aparelho/Aparelho.h"
#include "Componente/Sensor/Sensor.h"
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

    /*
    void saveProcessadorState(int idProcessador, const std::string &name); // Guarda o estado de um processador
    bool loadProcessadorState(const std::string &name); // Carrega o estado de um processador
    void deleteProcessadorState(const std::string &name); // Apaga o estado de um processador
    */
    ~Zona();
};


#endif //ZONA_H
