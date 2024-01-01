#include "Lampada.h"

Lampada::Lampada(int id, Zona &zona) : Aparelho(id, 'l', "lampada") {
    propriedades[LUZ_STR] = zona.getPropriedade(LUZ_STR);
}

void Lampada::update() {
    if (instantCount == 0) {
        if (state)
            propriedades[LUZ_STR]->setValor(900);
        else
            propriedades[LUZ_STR]->setValor(-900);
    }

    instantCount++;
}