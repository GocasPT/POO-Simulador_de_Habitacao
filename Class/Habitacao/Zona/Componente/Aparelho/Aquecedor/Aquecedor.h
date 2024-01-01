#ifndef AQUECEDOR_H
#define AQUECEDOR_H

#include "../Aparelho.h"
#include "../../../Zona.h"

class Aquecedor : public Aparelho {
public:
    Aquecedor(int id, Zona& zona);
    
    void ligar();
    void desligar();
};


#endif //AQUECEDOR_H
