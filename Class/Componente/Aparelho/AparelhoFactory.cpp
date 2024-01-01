#include "AparelhoFactory.h"

#include "Aparelhos.h"

TipoAparelho AparelhoFactory::stringToTipoeAparelho(const string &tipo) {
    static const map<string, TipoAparelho> tipoAparelhoMap = {
            {"Aquecedor",    TipoAparelho::AQUECEDOR},
            {"Aspersor",     TipoAparelho::ASPERSOR},
            {"Lampada",      TipoAparelho::LAMPADA},
            {"Refrigerador", TipoAparelho::REFRIGERADOR},
    };

    auto it = tipoAparelhoMap.find(tipo);
    if (it != tipoAparelhoMap.end())
        return it->second;

    return TipoAparelho::UNKNOWN;
}

Aparelho *AparelhoFactory::createAparelho(TipoAparelho tipo, int id, Zona &zona) {
    switch (tipo) {
        case TipoAparelho::AQUECEDOR:
            return new Aquecedor(id, zona);
        case TipoAparelho::ASPERSOR:
            return new Aspersor(id, zona);
        case TipoAparelho::LAMPADA:
            return new Lampada(id, zona);
        case TipoAparelho::REFRIGERADOR:
            return new Refrigerador(id, zona);
        default:
            return nullptr;
    }
}
