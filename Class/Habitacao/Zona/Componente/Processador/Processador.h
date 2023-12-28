#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include <vector>
#include "../Regra/Regra.h"
#include "../Aparelho/Aparelho.h"

using std::string;
using std::vector;

class Processador : public Componente {
    vector<Regra> regras; // Lista de regras
    vector<Aparelho *> aparelhos; // Lista de aparelhos associados

public:
    Processador(int id);

    void addRegra(int id, Sensor &sensor); // Adiciona uma regra
    void addAparelho(Aparelho &aparelho);   // Adiciona um aparelho

    bool validateRegras(); // Valida as regras
    void sendCommand(const string &command); // Envia um comando para os aparelhos

    ~Processador();
};

#endif //PROCESSADOR_H