#ifndef ASPERSOR_H
#define ASPERSOR_H

#include "../Aparelho.h"
#include "../../../Zona/Zona.h"

class Aspersor : public Aparelho {
public:
    Aspersor(int id, Zona &zona);

    void update() override;
};


#endif //ASPERSOR_H
