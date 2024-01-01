#ifndef AQUECEDOR_H
#define AQUECEDOR_H

#include "../Aparelho.h"
#include "../../../Zona/Zona.h"

class Aquecedor : public Aparelho {
public:
    Aquecedor(int id, Zona &zona);

    void update() override;
};


#endif //AQUECEDOR_H
