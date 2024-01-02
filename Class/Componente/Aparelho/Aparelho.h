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

    string getId() const override;
    string getName() const; // Getter do nome
    char getLetter() const; // Getter da letra
    bool getState() const; // Getter do estado

    virtual void readCommand(const string &command); // Lê um comando
    void ligar();
    void desligar();
    virtual void update()=0; // Atualiza as propriedades da zona

    string toString() const override; // Retorna uma string com a informacao do aparelho
};

#endif //APARELHO_H