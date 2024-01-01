#include "Aspersor.h"

Aspersor::Aspersor(int id, Zona &zona) : Aparelho(id, 's', "aspersor") {
    propriedades[HUMIDADE_STR] = zona.getPropriedade(HUMIDADE_STR);
    propriedades[VIBRACAO_STR] = zona.getPropriedade(VIBRACAO_STR);
    propriedades[FUMO_STR] = zona.getPropriedade(FUMO_STR);
}

void Aspersor::update() {
    if (instantCount == 0) {
        if (state) {
            if (propriedades[HUMIDADE_STR]->getValue() < 75)
                propriedades[HUMIDADE_STR]->setValor(propriedades[HUMIDADE_STR]->getValue() * 0.5);
        }
        else
            propriedades[VIBRACAO_STR]->setValor(-100);
    }

    instantCount++;
}