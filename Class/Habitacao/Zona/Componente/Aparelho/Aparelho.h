#ifndef APARELHO_H
#define APARELHO_H

#include <map>
#include "../../Propriedade/Propriedade.h"
#include "../Componente.h"

using std::string;

//TODO [Meta 2]: Virutalizar a class (hirearquia)
class Aparelho : public Componente {
protected:
    const string name; // Nome do aparelho
    const char letter; // Letra do aparelho
    bool state = false; // Estado do aparelho
    const std::map<string, Propriedade *> propriedades; // Lista de propriedades da zona que o aparelho vai modificar
    int instantCount = 0; // Contador de instantes

public:
    Aparelho(int id, char letter, string name, std::map<string, Propriedade *> propriedades);

    std::string getName() const; // Getter do nome
    char getLetter() const; // Getter da letra
    bool getState() const; // Getter do estado

    void readCommand(const string &command); // Lê um comando
    void toggleState(); // Altera o estado do aparelho
    void update(); // Atualiza as propriedades da zona
};

#endif //APARELHO_H