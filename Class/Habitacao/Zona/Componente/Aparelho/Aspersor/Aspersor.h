#ifndef ASPERSOR_H
#define ASPERSOR_H

#include <iostream>
#include "../Aparelho.h"

class Aspersor : public Aparelho {
private:

public:

    Aspersor(int id, char letter, string name, std::map<string, Propriedade *> propriedades);


    void ligar();

    void desligar();
};


#endif //ASPERSOR_H
