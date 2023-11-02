#include "Simulador.h"

#include <string>
#include <vector>

#define VIEW_WIDTH 80
#define VIEW_HEIGHT 25
#define CONSOLE_HEIGHT 3
#define INFO_WIDTH 35

using std::endl;

Simulador::Simulador() : term(term::Terminal::instance()) {
    winMenu = new term::Window(1, 1, term.getNumCols(), term.getNumRows());
    winView = nullptr;
    winConsole = nullptr;
    winInfo = nullptr;

    inSimulation = false;
}

void Simulador::menu() {
    std::ostringstream os;
    std::string input;
    int opt;

    //TODO [depois]: embelezar isto tudo
    os << "   _____  _                    _             _              " << endl;
    os << "  / ____|(_)                  | |           | |             " << endl;
    os << " | (___   _  _ __ ___   _   _ | |  __ _   __| |  ___   _ __ " << endl;
    os << R"(  \___ \ | || '_ ` _ \ | | | || | / _` | / _` | / _ \ | '__|)" << endl;
    os << "  ____) || || | | | | || |_| || || (_| || (_| || (_) || |   " << endl;
    os << R"( |_____/ |_||_| |_| |_| \__,_||_| \__,_| \__,_| \___/ |_|   )" << endl;
    os << "                                                            " << endl
       << endl;

    os << endl
       << "\t1 - Comecar o simulador" << endl
       << "\t2 - Sair do simulador" << endl
       << endl
       << "Escolha: ";

    //TODO [depois]: centriliza menu
    do {
        winMenu->clear();
        //*winMenu << move(term.getNumCols() / 2, term.getNumRows() / 2);
        *winMenu << os.str();
        *winMenu >> input;
        std::stringstream(input) >> opt;

        if(opt == 1) {
            break;
        } else if (opt == 2) {
            return;
        }
    } while (true);

    winMenu->clear();
    init();
}

void Simulador::init() {
    delete winMenu;
    winView = new term::Window(1, 1, VIEW_WIDTH, VIEW_HEIGHT);
    winConsole = new term::Window(1, VIEW_HEIGHT+1, VIEW_WIDTH, CONSOLE_HEIGHT);
    winInfo = new term::Window(VIEW_WIDTH+1, 1, INFO_WIDTH, VIEW_HEIGHT + CONSOLE_HEIGHT);
    start();
}

void Simulador::start() {
    inSimulation = true;
    run();
}

void Simulador::stop() { inSimulation = false; }

//TODO [depois]: scroll para o windInfo
void Simulador::run() {
    while (inSimulation) {
        std::string command;
        *winConsole >> command;

        std::istringstream comando(command);
        if (!validateCommand(comando)) {
            writeInfo("Comando valido\n");
        }

        //PLACEHOLDER
        update();
        winConsole->clear();
    }
}

//TODO: ler as zonas e desenhalhas na planta (aka view)
void Simulador::update() {
    draw(1, 1, 3, 2);
}

//TODO: verificar se o draw funciona
void Simulador::draw(int x, int y, int w, int h) {
    *winView << move(x, y);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++)
            *winView << '-';
        *winView << move(x, y + i + 1);
    }
}

void Simulador::writeInfo(std::string format, ...) {
    winInfo->clear();

    va_list args;
    va_start(args, format);

    //TODO [depois]: escrita do formato
    *winInfo << format;

    va_end(args);
}

bool Simulador::validateCommand(std::istringstream &comando) {
    std::vector<std::string> argv;

    while (comando) {
        std::string arg;
        comando >> arg;
        argv.push_back(arg);
    }
    argv.pop_back();

    //TODO [feature]: help command
    //TODO [depois]: comments para  separar a categoria dos comandos
    if (argv[0] == "prox") {
        if (argv.size() == 1) {
            //PLACEHOLDER
            writeInfo("Comando 'prox' [%d %d]\n", 1, 2);
            return true;
        } else {
            writeInfo("Comando 'prox' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "avanca") {
        if (argv.size() == 2) {
            writeInfo("Comando 'avanca'\n");
            return true;
        } else {
            writeInfo("Comando 'avanca' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "hnova") {
        if (argv.size() == 3) {
            writeInfo("Comando 'hnova'\n");
            return true;
        } else {
            writeInfo("Comando 'hnova' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "hrem") {
        if (argv.size() == 1) {
            writeInfo("Comando 'hrem'\n");
            return true;
        } else {
            writeInfo("Comando 'hrem' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "znova") {
        if (argv.size() == 3) {
            writeInfo("Comando 'znova'\n");
            return true;
        } else {
            writeInfo("Comando 'znova' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "zrem") {
        if (argv.size() == 2) {
            writeInfo("Comando 'zrem'\n");
            return true;
        } else {
            writeInfo("Comando 'zrem' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "zlista") {
        if (argv.size() == 1) {
            writeInfo("Comando 'zlista'\n");
            return true;
        } else {
            writeInfo("Comando 'zlista' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "zcomp") {
        if (argv.size() == 2) {
            writeInfo("Comando 'zcomp'\n");
            return true;
        } else {
            writeInfo("Comando 'zcomp' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "zprops") {
        if (argv.size() == 2) {
            writeInfo("Comando 'zprops'\n");
            return true;
        } else {
            writeInfo("Comando 'zprops' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "pmod") {
        if (argv.size() == 3) {
            writeInfo("Comando 'pmod'\n");
            return true;
        } else {
            writeInfo("Comando 'pmod' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "cnovo") {
        if (argv.size() == 4) {
            writeInfo("Comando 'cnovo'\n");
            return true;
        } else {
            writeInfo("Comando 'cnovo' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "crem") {
        if (argv.size() == 4) {
            writeInfo("Comando 'crem'\n");
            return true;
        } else {
            writeInfo("Comando 'crem' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "rnova") {
        if (argv.size() == 5) {
            writeInfo("Comando 'rnova'\n");
            return true;
        } else {
            writeInfo("Comando 'rnova' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "pmuda") {
        if (argv.size() == 4) {
            writeInfo("Comando 'pmuda'\n");
            return true;
        } else {
            writeInfo("Comando 'pmuda' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "rlista") {
        if (argv.size() == 3) {
            writeInfo("Comando 'rlista'\n");
            return true;
        } else {
            writeInfo("Comando 'rlista' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "rrem") {
        if (argv.size() == 4) {
            writeInfo("Comando 'rrem'\n");
            return true;
        } else {
            writeInfo("Comando 'rrem' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "asoc") {
        if (argv.size() == 4) {
            writeInfo("Comando 'asoc'\n");
            return true;
        } else {
            writeInfo("Comando 'asoc' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "ades") {
        if (argv.size() == 4) {
            writeInfo("Comando 'ades'\n");
            return true;
        } else {
            writeInfo("Comando 'ades' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "acom") {
        if (argv.size() == 4) {
            writeInfo("Comando 'acom'\n");
            return true;
        } else {
            writeInfo("Comando 'acom' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "psalva") {
        if (argv.size() == 4) {
            writeInfo("Comando 'psalva'\n");
            return true;
        } else {
            writeInfo("Comando 'psalva' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "prepoe") {
        if (argv.size() == 2) {
            writeInfo("Comando 'prepoe'\n");
            return true;
        } else {
            writeInfo("Comando 'prepoe' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "prem") {
        if (argv.size() == 2) {
            writeInfo("Comando 'prem'\n");
            return true;
        } else {
            writeInfo("Comando 'prem' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "plista") {
        if (argv.size() == 1) {
            writeInfo("Comando 'plista'\n");
            return true;
        } else {
            writeInfo("Comando 'plista' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "exec") {
        if (argv.size() == 2) {
            writeInfo("Comando 'exec'\n");
            return true;
        } else {
            writeInfo("Comando 'exec' invalido: Nao tem argumentos\n");
        }
    } else if (argv[0] == "sair") {
        if (argv.size() == 1) {
            writeInfo("Comando 'sair'\n");
            stop();
            return true;
        } else {
            writeInfo("Comando 'prox' invalido: Nao tem argumentos");
        }
    }

    return false;
}

Simulador::~Simulador() {
    delete winView;
    delete winConsole;
    delete winInfo;
}
