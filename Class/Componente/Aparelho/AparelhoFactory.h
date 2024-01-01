#ifndef APARELHOFACTORY_H
#define APARELHOFACTORY_H

#include "Aparelho.h"
#include "../../Zona/Zona.h"

enum class TipoAparelho {
    AQUECEDOR,
    ASPERSOR,
    LAMPADA,
    REFRIGERADOR,
    UNKNOWN
};

class AparelhoFactory {
public:
    static TipoAparelho stringToTipoeAparelho(const string &tipo);

    static Aparelho *createAparelho(TipoAparelho tipo, int id, Zona &zona);
};


#endif //APARELHOFACTORY_H
