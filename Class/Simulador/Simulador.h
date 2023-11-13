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
    Habitacao *habitacao;

    void init(int wide, int heigth);    // Inicializa o simulador
    void start();   // Inicia o simulador
    void stop();    // Para o simulador
    void run(); // Corre o simulador
    void next();
    void updateView();  // Atualiza a view do simulador
    bool validateCommand(std::istringstream &command);  // Valida um comando
    bool readFile(std::string filename);    // Le um ficheiro de configuracao

public:
    Simulador();

    void menu(); // Mostra o menu

    ~Simulador();
};


#endif //SIMULADOR_H
