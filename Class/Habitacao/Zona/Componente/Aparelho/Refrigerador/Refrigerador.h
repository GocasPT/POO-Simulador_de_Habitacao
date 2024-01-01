#ifndef REFRIGERADOR_H
#define REFRIGERADOR_H

#include "../Aparelho.h"
#include "../../../Zona.h"

class Refrigerador : public Aparelho{
public:
    Refrigerador(int id, Zona& zona);

    void ligar();
    void desligar();
};


#endif //REFRIGERADOR_H
