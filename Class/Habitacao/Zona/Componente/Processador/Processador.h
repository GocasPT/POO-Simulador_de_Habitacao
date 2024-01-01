#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include <vector>
#include "../Regra/Regra.h"
#include "../Aparelho/Aparelho.h"

using std::string, std::vector;

class Processador : public Componente {
    string comando;
    vector<Regra *> regras; // Lista de regras
    vector<Aparelho *> aparelhos; // Lista de aparelhos associados

public:
    Processador(int id, string comando);

    Processador& clone() const;
    Processador& operator=(const Processador &processador);

    vector<Regra *> getRegras() const; // Getter das regras

    void addRegra(Regra *regra); // Adiciona uma regra
    void removeRegra(const int id); // Remove uma regra
    void addAparelho(Aparelho *aparelho);   // Adiciona um aparelho
    void removeAparelho(const int id);  // Remove um aparelho

    bool validateRegras(); // Valida as regras
    void sendCommand(); // Envia um comando para os aparelhos

    ~Processador();

    void setComando(const string &command);
};

#endif //PROCESSADOR_H