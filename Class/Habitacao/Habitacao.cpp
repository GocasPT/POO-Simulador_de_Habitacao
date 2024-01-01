#include "Habitacao.h"

Habitacao::Habitacao(int wide, int heigh) {
    this->wide = wide;
    this->height = heigh;
    this->idCounter = 0;

    listaZonas = new Zona **[height];
    for (int i = 0; i < height; i++) {
        listaZonas[i] = new Zona *[wide];
        for (int j = 0; j < wide; j++)
            listaZonas[i][j] = nullptr;
    }
}

int Habitacao::getWide() const { return wide; }

int Habitacao::getHeight() const { return height; }

Zona ***Habitacao::getZonas() const { return listaZonas; }

Zona *Habitacao::getZona(int x, int y) const {
    if (x < 0 || x >= wide || y < 0 || y >= height)
        return nullptr;

    return listaZonas[y][x];
}

Zona *Habitacao::getZona(int id) const {
    for (int i = 0; i < wide; i++)
        for (int j = 0; j < height; j++) {
            if (!listaZonas[j][i]) continue;

            if (listaZonas[j][i]->getId() == id)
                return listaZonas[j][i];
        }
    return nullptr;
}

bool Habitacao::addZona(int x, int y) {
    if (x < 0 || x >= wide || y < 0 || y >= height)
        return false;

    if (listaZonas[y][x] != nullptr)
        return false;

    listaZonas[y][x] = new Zona(idCounter++);

    return true;
}

bool Habitacao::removeZona(int id) {
    for (int i = 0; i < wide; i++)
        for (int j = 0; j < height; j++) {
            if (listaZonas[j][i] == nullptr) continue;
            if (listaZonas[j][i]->getId() == id) {
                delete listaZonas[j][i];
                listaZonas[j][i] = nullptr;
                return true;
            }
        }

    return false;
}

Habitacao::~Habitacao() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < wide; j++) {
            delete listaZonas[i][j];
        }
        delete[] listaZonas[i];
    }
    delete[] listaZonas;
}
