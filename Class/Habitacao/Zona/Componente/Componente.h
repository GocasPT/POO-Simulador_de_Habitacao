#ifndef COMPONENTES_H
#define COMPONENTES_H

#include <string>

using std::string;

class Zona;

//TODO: Verirficar se é necessário ou sse fica aqui
enum class TipoComponente {
    SENSOR,
    APARELHO,
    PROCESSADOR,
    REGRA
};

class Componente {
protected:
    const char letterID; // Letra que identifica o componente
    const int id; // ID do componente

public:
    Componente(char c, int id);

    string getId() const; // Getter do id
    int getNumId() const; // Getter do número do id
    char getLetterID() const; // Getter da letra do id

    virtual string toString() const;
};

#endif //COMPONENTES_H
