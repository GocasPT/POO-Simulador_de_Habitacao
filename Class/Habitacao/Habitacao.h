#ifndef HABITACAO_H
#define HABITACAO_H


#include "Zona/Zona.h"

class Habitacao {
private:
    int wide, height;
    Zona ***listaZonas; // Matriz de ponteiros com tamanho fixo
    //TODO: ID's das zonas + outras classes

public:
    Habitacao(int wide, int heigh);

    int getWide() const; // Getter para a largura
    int getHeight() const;  // Getter para a altura
    Zona ***getListaZonas() const; // Getter para a lista de zonas
    Zona *getZona(int x, int y) const;  // Getter para uma zona especifica
    Zona *getZona(int id) const;   // Getter para uma zona especifica

    void setZona(int x, int y); // Setter para uma zona especifica

    ~Habitacao();
};


#endif //HABITACAO_H
