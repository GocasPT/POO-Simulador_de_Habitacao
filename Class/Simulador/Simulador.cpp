#include "Simulador.h"

#include <string>
#include <vector>

using std::endl;

Simulador::Simulador(): term(term::Terminal::instance()) {
    winView = new term::Window(1, 1, 10, 10);
    winConsole = new term::Window(12, 1, 10, 3);
    winInfo = new term::Window(1, 13, 5, 5);
    winMenu = nullptr;

    inSimulation = false;
}

void Simulador::init() {

}

void Simulador::start() {
    inSimulation = true;

    *winView << "Isto é a janela de visualização";

    std::istringstream comando("prox");
    validateCommand(comando);

    term.getchar();
}

void Simulador::stop() {

}

void Simulador::update() {

}

void Simulador::writeInfo() {

}

bool Simulador::validateCommand(std::istringstream &comando) {
    std::vector<std::string> argv;

    while (comando) {
        std::string arg;
        comando >> arg;
        argv.push_back(arg);
    }

    if (argv[0] == "prox") {
        if (argv.size() == 1) {
            //*winInfo << "Comando 'prox'";
            term << "Comando 'prox'";
            return true;
        } else {
            //*winInfo << "Comando 'prox' invalido: Nao tem argumentos";
            term << "Comando 'prox' invalido: Nao tem argumentos";
        }
    }

    return false;
}

Simulador::~Simulador() {
    delete winView;
    delete winConsole;
    delete winInfo;
    delete winMenu;
}
