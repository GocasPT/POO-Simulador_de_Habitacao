#include "Habitacao.h"

Habitacao::Habitacao(int wide, int heigh) {
    this->wide = wide;
    this->height = heigh;
}

int Habitacao::getWide() const { return wide; }

int Habitacao::getHeight() const { return height; }

Zona ***Habitacao::getListaZonas() const {
    return listaZonas;
}

Zona *Habitacao::getZona(int x, int y) const {
    if (x < 0 || x >= wide || y < 0 || y >= height)
        return nullptr;

    return listaZonas[y][x];
}

Zona *Habitacao::getZona(int id) const {
    /*
    for(int i = 0; i < wide; i++)
        for(int j = 0; j < height; j++)
            if(listaZonas[j][i]->getId() == id)
                return listaZonas[j][i];
    */
    return nullptr;
}

void Habitacao::setZona(int x, int y) {

}

Habitacao::~Habitacao() {

}
