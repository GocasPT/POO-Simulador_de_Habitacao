#ifndef ASPERSOR_H
#define ASPERSOR_H

#include "../Aparelho.h"
#include "../../../Zona.h"
    
class Aspersor : public Aparelho{
public:
    Aspersor(int id, Zona& zona);

    void ligar();
    void desligar();
};


#endif //ASPERSOR_H
