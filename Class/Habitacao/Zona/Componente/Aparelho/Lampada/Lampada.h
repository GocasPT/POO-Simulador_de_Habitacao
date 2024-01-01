#ifndef LAMPADA_H
#define LAMPADA_H

#include "../Aparelho.h"
#include "../../../Zona.h"

class Lampada : public Aparelho{
public:
    Lampada(int id, Zona& zona);

    void ligar();
    void desligar();
};



#endif //LAMPADA_H
