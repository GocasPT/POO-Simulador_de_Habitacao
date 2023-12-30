#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <map>
#include <vector>
#include "Propriedade/Propriedade.h"
#include "Componente/Componente.h"
#include "Componente/Sensor/Sensor.h"
#include "Componente/Processador/Processador.h"

using std::string;
using std::vector;

class Zona {
    const int id;
    int idCounter;
    std::map<string, Propriedade *> propriedades;
    std::map<string, Componente> componentes;
    //vector<Sensor> sensores;
    //vector<Processador> processadores;
    //vector<Aparelho> aparelhos;

public:
    Zona(int id);

    int getId() const; // Getter do id
    vector<Propriedade *> getPropriedades() const; // Getter das propriedades
    vector<Componente> getComponentes() const; // Getter dos componentes
    Propriedade *getPropriedade(const string &key) const; // Getter de uma propriedade
    const Componente *getComponente(const string &id) const; // Getter de um componente

    bool addComponente(const string &id); // Adiciona um componente Processador
    bool addComponente(const string &id, char type); // Adiciona um componente Sensor ou Aparlho
    bool addComponente(const string &id, char type, char rule); // Adiciona um componente Regra
    bool removeComponente(const string &id); // Remove um componente

    /*
    bool addSensor(const Sensor &sensor);
    bool removeSensor(const string &sensorId);

    bool addProcessador(const Processador &processador);
    bool removeProcessador(const string &processadorId);

    bool addAparelho(const Aparelho &aparelho);
    bool removeAparelho(const string &aparelhoId);
    */

    bool setPropriedade(const string &key, int value); // Altera uma propriedade

    ~Zona();
};

#endif //ZONA_H