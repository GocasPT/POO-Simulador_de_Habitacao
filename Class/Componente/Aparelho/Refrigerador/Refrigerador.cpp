#include "Refrigerador.h"

Refrigerador::Refrigerador(int id, Zona &zona) : Aparelho(id, 'r', "refrigerador") {
    propriedades[TEMPERATURA_STR] = zona.getPropriedade(TEMPERATURA_STR);
    propriedades[SOM_STR] = zona.getPropriedade(SOM_STR);
}

void Refrigerador::update() {
    if (instantCount == 0) {
        if (state)
            propriedades[SOM_STR]->setValor(20);
        else
            propriedades[SOM_STR]->setValor(-20);
    }

    if (instantCount % 3 == 0 && state)
        propriedades[TEMPERATURA_STR]->setValor(-1);

    instantCount++;
}