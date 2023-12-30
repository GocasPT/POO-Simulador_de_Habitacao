#ifndef REFRIGERADOR_H
#define REFRIGERADOR_H

#include <iostream>
#include "../Aparelho.h"

class Refrigerador : public Aparelho {
private:


public:

    Refrigerador(int id, char letter, string name, std::map<string, Propriedade *> propriedades);

    void ligar();

    void desligar();
};


#endif //REFRIGERADOR_H
