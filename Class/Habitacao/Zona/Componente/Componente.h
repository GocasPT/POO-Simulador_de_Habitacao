#ifndef COMPONENTES_H
#define COMPONENTES_H

#include <string>

//TODO: Verirficar se é necessário ou sse fica aqui
enum class TipoComponente {
    SENSOR,
    APARELHO,
    PROCESSADOR,
    REGRA
};

//TODO [Meta 2]: Virutalizar a class (hirearquia)
//TODO: Mudar string id para int id
class Componente {
protected:
    const char letterID; // Letra que identifica o componente
    const int id; // ID do componente

public:
    Componente(char c, int id);

    int getId() const; // Getter do id (número)
    char getLetterID() const; // Getter da letra do id
};

#endif //COMPONENTES_H
