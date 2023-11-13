#include "Simulador.h"

#include <string>
#include <vector>

#define MENU_WIDTH 85
#define MENU_HEIGHT 20
#define VIEW_WIDTH 180
#define VIEW_HEIGHT 55
#define CONSOLE_HEIGHT 3
#define INFO_WIDTH 50
#define ZONAS_WIDTH 30
#define ZONAS_HEIGHT 15

#define TAG_INPUT ">>"

using std::endl;

Simulador::Simulador() : term(term::Terminal::instance()) {
    winMenu = new term::Window(term.getNumRows() + term.getNumRows() / 2, 15, MENU_WIDTH, MENU_HEIGHT, false);
    winView = nullptr;
    winConsole = nullptr;
    winInfo = nullptr;
    winZones = nullptr;
    habitacao = nullptr;

    inSimulation = false;
}

void Simulador::menu() {
    std::ostringstream os;
    std::string input;
    int opt;

    os << "   _____  _                    _             _              " << endl
       << "  / ____|(_)                  | |           | |             " << endl
       << " | (___   _  _ __ ___   _   _ | |  __ _   __| |  ___   _ __ " << endl
       << R"(  \___ \ | || '_ ` _ \ | | | || | / _` | / _` | / _ \ | '__|)" << endl
       << "  ____) || || | | | | || |_| || || (_| || (_| || (_) || |   " << endl
       << R"( |_____/ |_||_| |_| |_| \__,_||_| \__,_| \__,_| \___/ |_|   )" << endl
       << "                                                            " << endl
       << endl
       << endl
       << "\t1 - Comecar o simulador" << endl
       << "\t2 - Sair do simulador" << endl
       << endl
       << "Escolha: ";

    do {
        winMenu->clear();
        *winMenu << os.str();
        *winMenu >> input;
        std::stringstream(input) >> opt;

        if (opt == 2) return;
    } while (opt != 1);

    int height = 0, wide = 0;
    do {
        winMenu->clear();
        *winMenu << "Numero de linhas: ";
        *winMenu >> input;
        std::stringstream(input) >> height;
        *winMenu << "Numero de colunas: ";
        *winMenu >> input;
        std::stringstream(input) >> wide;

        if (height < 2 || height > 4 || wide < 2 || wide > 4) {
            winMenu->clear();
            *winMenu << "Dimensoes invalidas!\n"
                     << "As dimensoes devem ser entre 2 e 4\n"
                     << "[ENTER PARA CONTINUAR]";
            winMenu->getchar();
        }

    } while (height < 2 || height > 4 || wide < 2 || wide > 4);

    winMenu->clear();
    term.clear();
    init(wide, height);
}

void Simulador::init(int wide, int heigth) {
    delete winMenu;
    winView = new term::Window(1, 1, VIEW_WIDTH, VIEW_HEIGHT);
    winConsole = new term::Window(1, VIEW_HEIGHT + 1, VIEW_WIDTH, CONSOLE_HEIGHT);
    winInfo = new term::Window(VIEW_WIDTH + 1, 1, INFO_WIDTH, VIEW_HEIGHT + CONSOLE_HEIGHT);

    habitacao = new Habitacao(wide, heigth);
    *winInfo << "Habitacao criada com sucesso!\n"
             << "Dimensoes: " << wide << " por " << heigth << "\n";

    winZones = new term::Window **[habitacao->getHeight()];
    for (int i = 0; i < habitacao->getHeight(); i++) {
        winZones[i] = new term::Window *[habitacao->getWide()];
        for (int j = 0; j < habitacao->getWide(); j++) {
            winZones[i][j] = new term::Window(j * ZONAS_WIDTH + 2, i * ZONAS_HEIGHT + 2, ZONAS_WIDTH, ZONAS_HEIGHT);
        }
    }

    winInfo->scrollok(true);

    start();
}

void Simulador::start() {
    inSimulation = true;
    run();
}

void Simulador::stop() {
    inSimulation = false;
    *winInfo << "\nSimulador terminado!\n"
            << "[ENTER PARA CONTINUAR]";
    winConsole->getchar();
}

void Simulador::run() {
    //* PLACEHOLDER
    updateView();

    while (inSimulation) {
        *winConsole << TAG_INPUT;

        std::string cmdInput;
        *winConsole >> cmdInput;

        std::istringstream cmd(cmdInput);
        if (!validateCommand(cmd)) {
            *winInfo << "Comando invalido!\n";
        }

        //PLACEHOLDER
        updateView();
        winConsole->clear();
    }
}

void Simulador::updateView() {
    for (int i = 0; i < habitacao->getHeight(); i++)
        for (int j = 0; j < habitacao->getWide(); j++) {
            winZones[i][j]->clear();
            //TODO: mostrar informação
        }
}

bool Simulador::validateCommand(std::istringstream &comando) {
    std::vector<std::string> argv;

    while (comando) {
        std::string arg;
        comando >> arg;
        argv.push_back(arg);
    }
    argv.pop_back();

    // Comando 'help'
    if (argv[0] == "help") {
        if (argv.size() == 1) {
            *winInfo << "Comnado 'help'\n"
                     << "help [comando]\n"
                     << "--all | -t | -h | -z | -r | -a | -p | -s\n";
        } else {
            for (const std::string &flag: argv) {
                if (flag == "--all") {
                    *winInfo << "Comandos para o tempo:\n"
                             << "prox\n"
                             << "avanca <n>\n"
                             << "\n"
                             << "Comandos para as habitacoes:\n"
                             << "hnova <num linhas> <num colunas>\n"
                             << "hrem\n"
                             << "znova <linha> <coluna>\n"
                             << "zrem <ID zona>\n"
                             << "zlista\n"
                             << "\n"
                             << "Comandos para as zonas:\n"
                             << "zcomp <ID zona>\n"
                             << "zprops <ID zona>\n"
                             << "pmod <ID zona> <nome> <valor>\n"
                             << "cnovo <ID zona> <s | p | a> <tipo | comando>\n"
                             << "crem <ID zona> <s | p | a> <ID>\n"
                             << "\n"
                             << "Comandos para os precessadores:\n"
                             << "rnova <ID zona> <ID proc. regras> <regra> <ID sensor> [param1] [param2] [...]\n"
                             << "pmuda <ID zona> <ID proc. regras> <novo comando>\n"
                             << "rlista <ID zona> <ID proc. regras>\n"
                             << "rrem <ID zona> <ID proc. regras> <ID regra>\n"
                             << "asoc <ID zona> <ID proc. regras> <ID aparelho>\n"
                             << "ades <ID zona> <ID proc. regras> <ID aparelho>\n"
                             << "\n"
                             << "Comandos para os aparelhos:\n"
                             << "acom <ID zona> <ID aparelho> <comando>\n"
                             << "\n"
                             << "Comandos para copiar/recuperar dos processadores:\n"
                             << "psalva <ID zona> <ID proc. regras> <nome>\n"
                             << "prepoe <nome>\n"
                             << "prem <nome>\n"
                             << "plista\n"
                             << "\n"
                             << "Comandos para o simulador:\n"
                             << "exec <nome de ficheiro>\n"
                             << "sair\n";
                    return true;
                }

                if (flag == "-t") {
                    *winInfo << "Comandos para o tempo:\n"
                             << "prox\n"
                             << "avanca <n>\n"
                             << "[ENTER PARA CONTINUAR]"
                             << "\n";
                    winInfo->getchar();
                    continue;
                }

                if (flag == "-h") {
                    *winInfo << "Comandos para as habitacoes:\n"
                             << "hnova <num linhas> <num colunas>\n"
                             << "hrem\n"
                             << "znova <linha> <coluna>\n"
                             << "zrem <ID zona>\n"
                             << "zlista\n"
                             << "[ENTER PARA CONTINUAR]"
                             << "\n";
                    winInfo->getchar();
                    continue;
                }

                if (flag == "-z") {
                    *winInfo << "Comandos para as zonas:\n"
                             << "zcomp <ID zona>\n"
                             << "zprops <ID zona>\n"
                             << "pmod <ID zona> <nome> <valor>\n"
                             << "cnovo <ID zona> <s | p | a> <tipo | comando>\n"
                             << "crem <ID zona> <s | p | a> <ID>\n"
                             << "[ENTER PARA CONTINUAR]"
                             << "\n";
                    winInfo->getchar();
                    continue;
                }

                if (flag == "-r") {
                    *winInfo << "Comandos para os precessadores:\n"
                             << "rnova <ID zona> <ID proc. regras> <regra> <ID sensor> [param1] [param2] [...]\n"
                             << "pmuda <ID zona> <ID proc. regras> <novo comando>\n"
                             << "rlista <ID zona> <ID proc. regras>\n"
                             << "rrem <ID zona> <ID proc. regras> <ID regra>\n"
                             << "asoc <ID zona> <ID proc. regras> <ID aparelho>\n"
                             << "ades <ID zona> <ID proc. regras> <ID aparelho>\n"
                             << "[ENTER PARA CONTINUAR]"
                             << "\n";
                    winInfo->getchar();
                    continue;
                }

                if (flag == "-a") {
                    *winInfo << "Comandos para os aparelhos:\n"
                             << "acom <ID zona> <ID aparelho> <comando>\n"
                             << "[ENTER PARA CONTINUAR]"
                             << "\n";
                    winInfo->getchar();
                    continue;
                }

                if (flag == "-p") {
                    *winInfo << "Comandos para copiar/recuperar dos processadores:\n"
                             << "psalva <ID zona> <ID proc. regras> <nome>\n"
                             << "prepoe <nome>\n"
                             << "prem <nome>\n"
                             << "plista\n"
                             << "[ENTER PARA CONTINUAR]"
                             << "\n";
                    winInfo->getchar();
                    continue;
                }

                if (flag == "-s") {
                    *winInfo << "Comandos para o simulador:\n"
                             << "exec <nome de ficheiro>\n"
                             << "sair\n";
                    winInfo->getchar();
                    continue;
                }
            }
            winInfo->curs_set(1);
            return true;
        }
    }

        // Comandos para o tempo
    else if (argv[0] == "prox") {
        if (argv.size() == 1) {
            *winInfo << "Comando 'prox'\n";
            return true;
        } else {
            *winInfo << "Comando 'prox' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "avanca") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'avanca'\n";
            return true;
        } else {
            *winInfo << "Comando 'avanca' invalido: Nao tem argumentos\n";
        }

        // Comandos para as habitacoes
    } else if (argv[0] == "hnova") {
        if (argv.size() == 3) {
            *winInfo << "Comando 'hnova'\n";
            return true;
        } else {
            *winInfo << "Comando 'hnova' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "hrem") {
        if (argv.size() == 1) {
            *winInfo << "Comando 'hrem'\n";
            return true;
        } else {
            *winInfo << "Comando 'hrem' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "znova") {
        if (argv.size() == 3) {
            *winInfo << "Comando 'znova'\n";
            return true;
        } else {
            *winInfo << "Comando 'znova' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "zrem") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'zrem'\n";
            return true;
        } else {
            *winInfo << "Comando 'zrem' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "zlista") {
        if (argv.size() == 1) {
            *winInfo << "Comando 'zlista'\n";
            return true;
        } else {
            *winInfo << "Comando 'zlista' invalido: Nao tem argumentos\n";
        }

        // Comandos para as zonas
    } else if (argv[0] == "zcomp") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'zcomp'\n";
            return true;
        } else {
            *winInfo << "Comando 'zcomp' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "zprops") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'zprops'\n";
            return true;
        } else {
            *winInfo << "Comando 'zprops' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "pmod") {
        if (argv.size() == 3) {
            *winInfo << "Comando 'pmod'\n";
            return true;
        } else {
            *winInfo << "Comando 'pmod' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "cnovo") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'cnovo'\n";
            return true;
        } else {
            *winInfo << "Comando 'cnovo' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "crem") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'crem'\n";
            return true;
        } else {
            *winInfo << "Comando 'crem' invalido: Nao tem argumentos\n";
        }

        // Comandos para os processadores
    } else if (argv[0] == "rnova") {
        if (argv.size() == 5) {
            *winInfo << "Comando 'rnova'\n";
            return true;
        } else {
            *winInfo << "Comando 'rnova' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "pmuda") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'pmuda'\n";
            return true;
        } else {
            *winInfo << "Comando 'pmuda' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "rlista") {
        if (argv.size() == 3) {
            *winInfo << "Comando 'rlista'\n";
            return true;
        } else {
            *winInfo << "Comando 'rlista' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "rrem") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'rrem'\n";
            return true;
        } else {
            *winInfo << "Comando 'rrem' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "asoc") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'asoc'\n";
            return true;
        } else {
            *winInfo << "Comando 'asoc' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "ades") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'ades'\n";
            return true;
        } else {
            *winInfo << "Comando 'ades' invalido: Nao tem argumentos\n";
        }

        // Comandos para os aparelhos
    } else if (argv[0] == "acom") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'acom'\n";
            return true;
        } else {
            *winInfo << "Comando 'acom' invalido: Nao tem argumentos\n";
        }

        // Comandos para copiar/recuperar dos processadores
    } else if (argv[0] == "psalva") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'psalva'\n";
            return true;
        } else {
            *winInfo << "Comando 'psalva' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "prepoe") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'prepoe'\n";
            return true;
        } else {
            *winInfo << "Comando 'prepoe' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "prem") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'prem'\n";
            return true;
        } else {
            *winInfo << "Comando 'prem' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "plista") {
        if (argv.size() == 1) {
            *winInfo << "Comando 'plista'\n";
            return true;
        } else {
            *winInfo << "Comando 'plista' invalido: Nao tem argumentos\n";
        }

        // Comandos para o simulador
    } else if (argv[0] == "exec") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'exec'\n";
            return true;
        } else {
            *winInfo << "Comando 'exec' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "sair") {
        if (argv.size() == 1) {
            *winInfo << "Comando 'sair'\n";
            stop();
            return true;
        } else {
            *winInfo << "Comando 'prox' invalido: Nao tem argumentos";
        }
    }

    return false;
}

//TODO: Fazer a função de leitura de ficheiro de comando
bool Simulador::readFile(std::string filename) {
    return false;
}

Simulador::~Simulador() {
    for (int i = 0; i < habitacao->getHeight(); i++)
        delete[] winZones[i];
    delete[] winZones;
    delete habitacao;
    delete winInfo;
    delete winConsole;
    delete winView;
    delete winMenu;
}
