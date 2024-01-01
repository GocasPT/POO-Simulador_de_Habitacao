#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <map>
#include <vector>
#include "Propriedade/Propriedade.h"
#include "Componente/Componente.h"
#include "Componente/Sensor/Sensor.h"
#include "Componente/Aparelho/Aparelho.h"
#include "Componente/Processador/Processador.h"

using std::string, std::vector, std::map;

class Zona {
    const int id;
    int idCounter;
    map<string, Propriedade *> propriedades;
    map<int, Componente* > componentes;

public:
    Zona(int id);

    int getId() const; // Getter do id
    int getIdCounter() const; // Getter do idCounter
    vector<Propriedade *> getPropriedades() const; // Getter das propriedades
    vector<Componente *> getComponentes() const; // Getter dos componentes
    Propriedade *getPropriedade(const string &key) const; // Getter de uma propriedade
    const Componente *getComponente(const int id) const; // Getter de um componente

    bool addComponente(Aparelho* aparelho); // Adiciona um aparelho
    bool addComponente(Processador* processador); // Adiciona um processador
    bool addComponente(Sensor* sensor); // Adiciona um sensor
    bool removeComponente(char tipoComponente, const int id); // Remove um componente

    bool setPropriedade(const string &key, int value); // Altera uma propriedade

    string toString() const; // Retorna uma string com a informacao da zona

    ~Zona();
};

#endif //ZONA_H