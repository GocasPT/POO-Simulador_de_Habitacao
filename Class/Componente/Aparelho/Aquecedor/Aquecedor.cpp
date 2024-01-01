#include <sstream>
#include "Aquecedor.h"

using std::cout, std::endl, std::ostringstream;

Aquecedor::Aquecedor(int id, Zona &zona) : Aparelho(id, 'a', "aquecedor") {
    propriedades[TEMPERATURA_STR] = zona.getPropriedade(TEMPERATURA_STR);
    propriedades[SOM_STR] = zona.getPropriedade(SOM_STR);
}

void Aquecedor::update() {
    if (state) {
        if (instantCount == 0)
            propriedades[SOM_STR]->setValor(5);

        if (instantCount % 3 == 0 || propriedades[TEMPERATURA_STR]->getValue() < 50)
            propriedades[TEMPERATURA_STR]->setValor(1);
    } else
        if (instantCount == 0)
            propriedades[SOM_STR]->setValor(-5);

    instantCount++;
}
