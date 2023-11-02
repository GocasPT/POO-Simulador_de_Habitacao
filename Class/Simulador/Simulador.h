#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <sstream>

#include "../../Lib/Terminal.h"
//#include "../Habitacao/Habitacao.h"

class Simulador {
    // Variaveis da UI
    term::Terminal &term;
    term::Window *winMenu, *winView, *winConsole, *winInfo; //TODO [?]: fazer mais windows

    // Variaveis do Simulador
    bool inSimulation;
    //Habitacao habitacao;

    // Metodos
    void init();
    void start();
    void stop();
    void run();
    void update();
    void draw(int x, int y, int w, int h);
    //void draw(Zona& zona);
    void writeInfo(std::string format, ...);
    bool validateCommand(std::istringstream &command);

public:
    // Construtor
    Simulador();

    // Metodos
    void menu();

    // Desconsstrjtoe
    ~Simulador();
};


#endif //SIMULADOR_H
