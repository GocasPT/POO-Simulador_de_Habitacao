#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <sstream>

#include "../../Lib/Terminal.h"

class Simulador {
    // Variaveis da UI
    term::Terminal &term;
    term::Window *winView, *winConsole, *winInfo;
    //TODO: verificar se é fixe fazer a janela de menu;
    term::Window *winMenu;

    // Variaveis do Simulador
    bool inSimulation;

public:
    // Construtor
    Simulador();

    // Metodos
    void init();
    void start();
    void stop();
    void update();
    void writeInfo();
    bool validateCommand(std::istringstream &command);

    // Deconstrutor
    ~Simulador();
};


#endif //SIMULADOR_H
