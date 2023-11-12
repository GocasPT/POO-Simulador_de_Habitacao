#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <map>
#include "Propriedade/Propriedade.h"
#include "Componentes/Processador/Processador.h"
#include "Componentes/Aparelho/Aparelho.h"
#include "Componentes/Sensor/Sensor.h"


class Zona {
private:
    int id;
    std::map<std::string, Propriedade*> propriedades; //mapa de ponteiro de objetos
    std::map<int, Sensor*> sensores;
    std::map<int, Aparelho*> aparelhos;
    std::map<int, Processador*> processadores;

public:
    Zona();

    ~Zona();
};


#endif //ZONA_H
