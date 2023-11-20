#include "Simulador.h"

#include <string>
#include <vector>
#include <fstream>

#define MENU_WIDTH 85
#define MENU_HEIGHT 20
#define VIEW_WIDTH 180
#define VIEW_HEIGHT 55
#define CONSOLE_HEIGHT 3
#define INFO_WIDTH 50
#define ZONAS_WIDTH 40
#define ZONAS_HEIGHT 12

#define TAG_INPUT ">>"

#define FILE_PATH "../File/"

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

    winMenu->clear();
    term.clear();
    init();
}

void Simulador::init() {
    delete winMenu;
    winView = new term::Window(1, 1, VIEW_WIDTH, VIEW_HEIGHT);
    winConsole = new term::Window(1, VIEW_HEIGHT + 1, VIEW_WIDTH, CONSOLE_HEIGHT);
    winInfo = new term::Window(VIEW_WIDTH + 1, 1, INFO_WIDTH, VIEW_HEIGHT + CONSOLE_HEIGHT);

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

void Simulador::next() {

}

void Simulador::updateView() {
    if (habitacao == nullptr) return;

    for (int i = 0; i < habitacao->getHeight(); i++)
        for (int j = 0; j < habitacao->getWide(); j++) {
            winZones[i][j]->clear();
            if (habitacao->getZona(i, j) != nullptr) {
                *winInfo << "Zona nao encontrada!\n";
                Zona &zona = *habitacao->getZona(i, j);
                *winZones[i][j] << zona.getId();
            }
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
                             << "pmod <ID zona> <name> <value>\n"
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
                             << "psalva <ID zona> <ID proc. regras> <name>\n"
                             << "prepoe <name>\n"
                             << "prem <name>\n"
                             << "plista\n"
                             << "\n"
                             << "Comandos para o simulador:\n"
                             << "exec <name de ficheiro>\n"
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
                             << "pmod <ID zona> <name> <value>\n"
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
                             << "psalva <ID zona> <ID proc. regras> <name>\n"
                             << "prepoe <name>\n"
                             << "prem <name>\n"
                             << "plista\n"
                             << "[ENTER PARA CONTINUAR]"
                             << "\n";
                    winInfo->getchar();
                    continue;
                }

                if (flag == "-s") {
                    *winInfo << "Comandos para o simulador:\n"
                             << "exec <name de ficheiro>\n"
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

            if (!checkHabitacao()) return true;

            next();
            return true;
        } else {
            *winInfo << "Comando 'prox' invalido - prox\n";
        }
    } else if (argv[0] == "avanca") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'avanca' com argumento " << argv[1] << "\n";

            if (!checkHabitacao()) return true;

            for (int i = 0; i < std::stoi(argv[1]); i++)
                next();
            return true;
        } else {
            *winInfo << "Comando 'avanca' invalido - avanca <n>\n";
        }

        // Comandos para as habitacoes
    } else if (argv[0] == "hnova") {
        if (argv.size() == 3) {
            *winInfo << "Comando 'hnova' com argumentos [" << argv[1] << " " << argv[2] << "]\n";
            if (!createHabitacao(std::stoi(argv[1]), std::stoi(argv[2])))
                *winInfo << "Dimensoes invalidas!\n";
            return true;
        } else {
            *winInfo << "Comando 'hnova' invalido - hnova <num linhas> <num colunas>\n";
        }
    } else if (argv[0] == "hrem") {
        if (argv.size() == 1) {
            *winInfo << "Comando 'hrem'\n";
            deleteHabitacao();
            return true;
        } else {
            *winInfo << "Comando 'hrem' invalido - hrem\n";
        }
    } else if (argv[0] == "znova") {
        if (argv.size() == 3) {
            *winInfo << "Comando 'znova' com argumentos [" << argv[1] << " " << argv[2] << "]\n";

            if (!checkHabitacao()) return true;

            int x = std::stoi(argv[1]);
            int y = std::stoi(argv[2]);

            if (!habitacao->addZona(x, y)) {
                *winInfo << "Posicao invalida!\n";
                return true;
            }

            *winInfo << "Zona adicionada com sucesso!\n"
                     << "ID: " << habitacao->getZona(x, y)->getId() << "\n";
            return true;
        } else {
            *winInfo << "Comando 'znova' invalido - znova <linha> <coluna>\n";
        }
    } else if (argv[0] == "zrem") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'zrem' com argumento " << argv[1] << "\n";

            if (!checkHabitacao()) return true;

            if (!habitacao->removeZona(std::stoi(argv[1]))) {
                *winInfo << "Zona nao encontrada!\n";
                return true;
            }

            *winInfo << "Zona removida com sucesso!\n";
            return true;
        } else {
            *winInfo << "Comando 'zrem' invalido - zrem <ID zona>\n";
        }
    } else if (argv[0] == "zlista") {
        if (argv.size() == 1) {
            *winInfo << "Comando 'zlista'\n";

            if (!checkHabitacao()) return true;

            Zona ***listaZonas = habitacao->getListaZonas();
            int wide = habitacao->getWide();
            int height = habitacao->getHeight();

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < wide; j++) {
                    Zona *zona = listaZonas[i][j];

                    if (!zona) continue;

                    int aparelhos = 0;
                    int sensores = 0;
                    int processadores = 0;

                    for (const auto &componenete: zona->getComponentes()) {
                        if (componenete.second.getType() == APARELHO) aparelhos++;
                        else if (componenete.second.getType() == SENSOR) sensores++;
                        else if (componenete.second.getType() == PROCESSADOR) processadores++;
                    }

                    *winInfo << "Zona '" << zona->getId() << "'\n";
                    *winInfo << "Aparelhos: " << aparelhos << "\n";
                    *winInfo << "Sensores: " << sensores << "\n";
                    *winInfo << "Processadores: " << processadores << "\n\n";
                }
            }

            return true;
        } else {
            *winInfo << "Comando 'zlista' invalido - zlista\n";
        }

        // Comandos para as zonas
    } else if (argv[0] == "zcomp") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'zcomp' com argumento " << argv[1] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(std::stoi(argv[1]));
            if (!zona) {
                *winInfo << "Zona nao encontrada!\n";
                return true;
            }

            for (const auto &componente: zona->getComponentes()) {
                *winInfo << "Componente '" << componente.second.getId() << "'\n";
                *winInfo << "Tipo: " << componente.second.getType() << "\n";
            }

            return true;
        } else {
            *winInfo << "Comando 'zcomp' invalido - zcomp <ID zona>\n";
        }
    } else if (argv[0] == "zprops") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'zprops' com argumento " << argv[1] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(std::stoi(argv[1]));
            if (!zona) {
                *winInfo << "Zona nao encontrada!\n";
                return true;
            }

            for (const auto &propriedade: zona->getPropriedades()) {
                *winInfo << "Propriedade '" << propriedade.second.getName() << "'\n";
                *winInfo << "Valor: " << propriedade.second.getValue() << "\n\n";
            }

            return true;
        } else {
            *winInfo << "Comando 'zprops' invalido - zprops <ID zona>\n";
        }
    } else if (argv[0] == "pmod") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'pmod' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "]\n";
            return true;
        } else {
            *winInfo << "Comando 'pmod' invalido - pmod <ID zona> <name> <value>\n";
        }
    } else if (argv[0] == "cnovo") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'cnovo' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'cnovo' invalido - cnovo <ID zona> <s | p | a> <tipo | comando>\n";
        }
    } else if (argv[0] == "crem") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'crem' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'crem' invalido - crem <ID zona> <s | p | a> <ID>\n";
        }

        // Comandos para os processadores
    } else if (argv[0] == "rnova") {
        //TODO: verificar o tamanho de arumentos
        if (argv.size() == 5) {
            *winInfo << "Comando 'rnova' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << " "
                     << argv[4] << "\n";
            return true;
        } else {
            *winInfo
                    << "Comando 'rnova' invalido - rnova <ID zona> <ID proc. regras> <regra> <ID sensor> [param1] [param2] [...]\n";
        }
    } else if (argv[0] == "pmuda") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'pmuda' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'pmuda' invalido - pmuda <ID zona> <ID proc. regras> <novo comando>\n";
        }
    } else if (argv[0] == "rlista") {
        if (argv.size() == 3) {
            *winInfo << "Comando 'rlista' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'rlista' invalido - rlista <ID zona> <ID proc. regras>\n";
        }
    } else if (argv[0] == "rrem") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'rrem' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'rrem' invalido - rrem <ID zona> <ID proc. regras> <ID regra>\n";
        }
    } else if (argv[0] == "asoc") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'asoc' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'asoc' invalido - asoc <ID zona> <ID proc. regras> <ID aparelho>\n";
        }
    } else if (argv[0] == "ades") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'ades' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'ades' invalido - ades <ID zona> <ID proc. regras> <ID aparelho>\n";
        }

        // Comandos para os aparelhos
    } else if (argv[0] == "acom") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'acom' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'acom' invalido - acom <ID zona> <ID aparelho> <comando>\n";
        }

        // Comandos para copiar/recuperar dos processadores
    } else if (argv[0] == "psalva") {
        if (argv.size() == 4) {
            *winInfo << "Comando 'psalva' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'psalva' invalido - psalva <ID zona> <ID proc. regras> <name>\n";
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
            *winInfo << "Comando 'prem' com argumento " << argv[1] << "\n";
            return true;
        } else {
            *winInfo << "Comando 'prem' invalido - prem <name>\n";
        }
    } else if (argv[0] == "plista") {
        if (argv.size() == 1) {
            *winInfo << "Comando 'plista'\n";
            return true;
        } else {
            *winInfo << "Comando 'plista' invalido - plista\n";
        }

        // Comandos para o simulador
    } else if (argv[0] == "exec") {
        if (argv.size() == 2) {
            *winInfo << "Comando 'exec' com argumento " << argv[1] << "\n";
            if (!readFile(argv[1])) {
                *winInfo << "Ficheiro nao encontrado!\n";
            }
            return true;
        } else {
            *winInfo << "Comando 'exec' invalido - exec <name de ficheiro>\n";
        }
    } else if (argv[0] == "sair") {
        if (argv.size() == 1) {
            *winInfo << "Comando 'sair'\n";
            stop();
            return true;
        } else {
            *winInfo << "Comando 'sair' invalido - sair";
        }
    }

    return false;
}

bool Simulador::readFile(const std::string &filename) {
    std::fstream file(FILE_PATH + filename, std::ios::in);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream cmd(line);
            if (!validateCommand(cmd)) {
                *winInfo << "Comando invalido!\n";
            }
        }

        return true;
    }

    return false;
}

bool Simulador::checkHabitacao() {
    if (!habitacao) {
        *winInfo << "Nao existe habitacao!\n";
        return false;
    }

    return true;
}

bool Simulador::createHabitacao(int wide, int heigth) {
    if (wide < 2 || wide > 4 || heigth < 2 || heigth > 4) return false;

    deleteHabitacao();

    habitacao = new Habitacao(wide, heigth);
    *winInfo << "Habitacao criada com sucesso!\n"
             << "Dimensoes: " << wide << " por " << heigth << "\n";

    winZones = new term::Window **[heigth];
    for (int i = 0; i < heigth; i++) {
        winZones[i] = new term::Window *[wide];
        for (int j = 0; j < wide; j++) {
            winZones[i][j] = new term::Window(j * ZONAS_WIDTH + 2, i * ZONAS_HEIGHT + 2, ZONAS_WIDTH, ZONAS_HEIGHT);
        }
    }

    return true;
}

void Simulador::deleteHabitacao() {
    if (habitacao == nullptr) return;

    for (int i = 0; i < habitacao->getHeight(); i++) {
        for (int j = 0; j < habitacao->getWide(); j++)
            delete winZones[i][j];
        delete[] winZones[i];
    }
    delete[] winZones;
    delete habitacao;

    habitacao = nullptr;
}

Simulador::~Simulador() {
    deleteHabitacao();
    delete winInfo;
    delete winConsole;
    delete winView;
    delete winMenu;
}
