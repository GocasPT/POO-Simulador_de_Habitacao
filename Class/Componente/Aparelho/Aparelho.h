#ifndef APARELHO_H
#define APARELHO_H

#include <map>
#include "../../Propriedade/Propriedade.h"
#include "../Componente.h"

using std::map;

class Aparelho : public Componente {
protected:
    const string name; // Nome do aparelho
    char letter; // Letra do aparelho
    bool state = false; // Estado do aparelho
    map<string, Propriedade *> propriedades; // Lista de propriedades da zona que o aparelho vai modificar
    int instantCount = 0; // Contador de instantes

public:
    Aparelho(int id, char letter, string name);

    string getName() const; // Getter do nome
    char getLetter() const; // Getter da letra
    bool getState() const; // Getter do estado

    virtual void readCommand(const string &command)=0; // Lê um comando
    void toggleState(); // Altera o estado do aparelho
    virtual void update()=0; // Atualiza as propriedades da zona

    virtual string toString() const override; // Retorna uma string com a informacao do aparelho
};

#endif //APARELHO_H