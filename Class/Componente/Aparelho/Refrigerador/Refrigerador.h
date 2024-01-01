#ifndef REFRIGERADOR_H
#define REFRIGERADOR_H

#include "../Aparelho.h"
#include "../../../Zona/Zona.h"

class Refrigerador : public Aparelho {
public:
    Refrigerador(int id, Zona &zona);

    void update() override;
};


#endif //REFRIGERADOR_H
