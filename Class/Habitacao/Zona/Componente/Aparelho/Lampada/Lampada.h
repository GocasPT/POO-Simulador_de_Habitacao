#ifndef LAMPADA_H
#define LAMPADA_H

#include <iostream>
#include "../Aparelho.h"


class Lampada : public Aparelho {
private:


public:

    Lampada(int id, char letter, string name, std::map<string, Propriedade *> propriedades);


    void ligar();

    void desligar();
};



#endif //LAMPADA_H
