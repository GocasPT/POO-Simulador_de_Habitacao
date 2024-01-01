#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include <vector>
#include "../Regra/Regra.h"
#include "../Aparelho/Aparelho.h"

using std::string, std::vector;

class Processador : public Componente {
    string comando;
    vector<Regra> regras; // Lista de regras
    vector<Aparelho *> aparelhos; // Lista de aparelhos associados

public:
    Processador(int id, string comando);

    void addRegra(Regra &regra); // Adiciona uma regra
    void addAparelho(Aparelho *aparelho);   // Adiciona um aparelho

    bool validateRegras(); // Valida as regras
    void sendCommand(); // Envia um comando para os aparelhos

    ~Processador();
};

#endif //PROCESSADOR_H