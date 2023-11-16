#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <map>
#include "Propriedade/Propriedade.h"
#include "Componentes/Processador/Processador.h"
#include "Componentes/Aparelho/Aparelho.h"
#include "Componentes/Sensor/Sensor.h"


class Zona {
    const int id;
    /*std::map<std::string, Propriedade> propriedades;
    std::map<int, Sensor> sensores;
    std::map<int, Aparelho> aparelhos;
    std::map<int, Processador> processadores;*/

public:
    Zona(int id);

    int getId() const;

    ~Zona();
};


#endif //ZONA_H
