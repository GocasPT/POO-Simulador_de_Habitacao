#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <sstream>

#include "../../Lib/Terminal.h"
#include "../Habitacao/Habitacao.h"

class Simulador {
    term::Terminal &term;   // Referencia para o terminal
    term::Window *winMenu, *winView, *winConsole, *winInfo; // Janelas
    term::Window ***winZones; // Janelas das zonas

    bool inSimulation;  // Flag que indica se o simulador esta a correr
    Habitacao *habitacao; // Ponteiro para a habitacao

    void init();    // Inicializa o simulador
    void start();   // Inicia o simulador
    void stop();    // Para o simulador
    void run(); // Loop principal do simulador
    void next(); // Proximo passo do simulador
    void updateView();  // Atualiza a view do simulador
    bool validateCommand(std::istringstream &command);  // Valida um comando
    bool readFile(const std::string &filename);    // Le um ficheiro de configuracao

    bool createHabitacao(int wide, int heigth); // Cria uma habitacao
    void deleteHabitacao(); // Apaga a habitacao


public:
    Simulador();

    void menu(); // Mostra o menu

    ~Simulador();
};


#endif //SIMULADOR_H
