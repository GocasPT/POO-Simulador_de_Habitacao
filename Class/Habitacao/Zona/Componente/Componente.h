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

//TODO [Meta 2]: Virutalizar a class (hirearquia)
//TODO: Mudar string id para int id
class Componente {
protected:
    const char letterID; // Letra que identifica o componente
    const int id; // ID do componente

public:
    Componente(char c, int id);

    string getId() const; // Getter do id
    int getNumId() const; // Getter do número do id
    char getLetterID() const; // Getter da letra do id

    string toString() const; //TODO: virtualizar
};

#endif //COMPONENTES_H
