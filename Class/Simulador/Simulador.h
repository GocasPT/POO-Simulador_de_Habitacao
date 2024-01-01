#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <sstream>

#include "../Habitacao/Habitacao.h"
#include "../../Lib/Terminal/Terminal.h"

using std::string, std::istringstream, std::map, std::pair;

class Simulador {
    term::Terminal &term;   // Referencia para o terminal
    term::Window *winMenu, *winView, *winConsole, *winInfo; // Janelas
    term::Window ***winZones; // Janelas das zonas

    bool inSimulation;  // Flag que indica se o simulador esta a correr
    Habitacao *habitacao; // Ponteiro para a habitacao
    int idCount;
    map<string, pair<int, Processador *>> processadorStatesList; // Lista de processadores

    void init();    // Inicializa o simulador
    void start();   // Inicia o simulador
    void stop();    // Para o simulador
    void run(); // Loop principal do simulador
    void next(); // Proximo passo do simulador
    void updateView();  // Atualiza a view do simulador
    bool validateCommand(istringstream &command);  // Valida um comando
    bool readFile(const string &filename);    // Le um ficheiro de configuracao

    bool checkHabitacao(); // Verifica se a habitacao existe
    bool createHabitacao(int wide, int heigth); // Cria uma habitacao
    void deleteHabitacao(); // Apaga a habitacao

    void saveProcessadorState(int idZona, int idProcessador, const string &name); // Guarda o estado de um processador
    bool loadProcessadorState(const std::string &name); // Carrega o estado de um processador
    void deleteProcessadorState(const std::string &name); // Apaga o estado de um processador
    vector<pair<string, pair<int, Processador *>>> getProcessadoresStates(); // Retorna os processadores da habitacao

public:
    Simulador();

    void menu(); // Mostra o menu

    ~Simulador();
};


#endif //SIMULADOR_H
