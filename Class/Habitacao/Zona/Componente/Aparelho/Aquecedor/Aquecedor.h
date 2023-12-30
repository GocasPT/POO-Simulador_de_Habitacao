#ifndef AQUECEDOR_H
#define AQUECEDOR_H

#include "../Aparelho.h"
#include <iostream>

using std::string;

class Aquecedor : public Aparelho {
private:

public:

    Aquecedor(int id, char letter, string name, std::map<string, Propriedade *> propriedades);

    void ligar() ;


    void desligar();
};


#endif //AQUECEDOR_H
