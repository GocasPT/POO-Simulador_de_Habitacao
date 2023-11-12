#ifndef HABITACAO_H
#define HABITACAO_H


#include "Zona/Zona.h"

class Habitacao {
private:
    int wide, high;
    Zona** *listaZonas; // Matriz de ponteiros com tamanho fixo

public:
    Habitacao(int wide, int high);

    ~Habitacao();
};


#endif //HABITACAO_H
