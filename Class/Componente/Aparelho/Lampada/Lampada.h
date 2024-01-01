#ifndef LAMPADA_H
#define LAMPADA_H

#include "../Aparelho.h"
#include "../../../Zona/Zona.h"

class Lampada : public Aparelho {
public:
    Lampada(int id, Zona &zona);

    void update() override;
};


#endif //LAMPADA_H
