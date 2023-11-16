#ifndef HABITACAO_H
#define HABITACAO_H


#include "Zona/Zona.h"

class Habitacao {
    int wide, height;
    Zona ***listaZonas; // Matriz de ponteiros com tamanho fixo
    int idCounter;
    //TODO: ID's das zonas + outras classes

public:
    Habitacao(int wide, int heigh);

    int getWide() const; // Getter para a largura
    int getHeight() const;  // Getter para a altura
    Zona *getZona(int x, int y) const;  // Getter para uma zona especifica
    Zona *getZona(int id) const;   // Getter para uma zona especifica

    bool addZona(int x, int y); // Setter para uma zona especifica
    bool removeZona(int id);  // Remove uma zona especifica

    ~Habitacao();
};


#endif //HABITACAO_H
