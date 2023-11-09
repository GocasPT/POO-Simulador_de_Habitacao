#ifndef HABITACAO_H
#define HABITACAO_H


#include "Zona/Zona.h"

class Habitacao {
private:
    int numColunas;
    int numLinhas;
    Zona*** listaZonas; // Matriz de ponteiros com tamanho fixo

public:
    Habitacao(int numColunas, int numLinhas);

    ~Habitacao();
};


#endif //HABITACAO_H
