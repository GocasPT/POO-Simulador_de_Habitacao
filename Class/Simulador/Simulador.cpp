#include "Simulador.h"
#include "../../Lib/utils/utils.h"
#include "../Componente/Sensor/SensorFactory.h"
#include "../Componente/Aparelho/AparelhoFactory.h"

#include <string>
#include <vector>
#include <fstream>
#include <iosfwd>

#define MENU_WIDTH 75
#define MENU_HEIGHT 20
#define VIEW_WIDTH 150
#define VIEW_HEIGHT 55
#define CONSOLE_HEIGHT 3
#define INFO_WIDTH 50
#define ZONAS_WIDTH (VIEW_WIDTH / 4 - 1)
#define ZONAS_HEIGHT (VIEW_HEIGHT / 4)

#define TAG_INPUT ">>"

#define FILE_PATH "../File/"

using std::endl, std::ostringstream, std::string, std::stringstream, std::vector, std::fstream, std::ios;

Simulador::Simulador() : term(term::Terminal::instance()) {
    winMenu = new term::Window(term.getNumRows() + term.getNumRows() / 2, 15, MENU_WIDTH, MENU_HEIGHT, false);
    winView = nullptr;
    winConsole = nullptr;
    winInfo = nullptr;
    winZones = nullptr;
    habitacao = nullptr;

    inSimulation = false;
    idCount = 0;
}

void Simulador::menu() {
    ostringstream os;
    string input;
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
        stringstream(input) >> opt;

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
    deleteHabitacao();
    *winInfo << "Simulador terminado!\n"
             << "[ENTER PARA CONTINUAR]";
    winConsole->getchar();
}

void Simulador::run() {
    updateView();

    while (inSimulation) {
        *winConsole << TAG_INPUT;

        string cmdInput;
        *winConsole >> cmdInput;

        istringstream cmd(cmdInput);
        if (!validateCommand(cmd)) {
            *winInfo << "Comando invalido!\n";
        }

        updateView();
        winConsole->clear();
    }
}

void Simulador::next() {
    if (habitacao == nullptr) return;

    for (int i = 0; i < habitacao->getHeight(); i++)
        for (int j = 0; j < habitacao->getWide(); j++) {
            auto zona = habitacao->getZona(i, j);
            if (zona)
                zona->update();
        }
}

void Simulador::updateView() {
    if (habitacao == nullptr) return;

    for (int i = 0; i < habitacao->getHeight(); i++)
        for (int j = 0; j < habitacao->getWide(); j++) {
            winZones[i][j]->clear();
            if (habitacao->getZona(i, j) != nullptr) {
                ostringstream oss, ap, se, pr, re;

                Zona &zona = *habitacao->getZona(i, j);
                oss << "Zona Id: " << zona.getId() << "\n";

                for (const auto &componente: zona.getComponentes()) {
                    switch (componente->getLetterID()) {
                        case 'a':
                            ap << componente->getId() << " ";
                            break;
                        case 's':
                            se << componente->getId() << " ";
                            break;
                        case 'p':
                            pr << componente->getId() << " ";
                            for (const auto &regra: ((Processador *) componente)->getRegras())
                                re << regra->getId() << " ";
                            break;
                    }
                }

                oss << "Aparelhos: " << ap.str() << "\n\n"
                    << "Sensores: " << se.str() << "\n\n"
                    << "Processadores: " << pr.str() << "\n\n"
                    << "Regras: " << re.str() << "\n\n";

                *winZones[i][j] << oss.str();
            }
        }
}

bool Simulador::validateCommand(istringstream &comando) {
    vector<string> argv;

    while (comando) {
        string arg;
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
            for (const string &flag: argv) {
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
            *winInfo << "\nComando 'prox'\n";

            if (!checkHabitacao()) return true;

            next();

            return true;
        } else {
            *winInfo << "\nComando 'prox' invalido - prox\n";
        }
    } else if (argv[0] == "avanca") {
        if (argv.size() == 2 && isNumber(argv[1])) {
            *winInfo << "\nComando 'avanca' com argumento " << argv[1] << "\n";

            if (!checkHabitacao()) return true;

            for (int i = 0; i < stoi(argv[1]); i++)
                next();

            return true;
        } else {
            *winInfo << "\nComando 'avanca' invalido - avanca <n>\n";
        }

        // Comandos para as habitacoes
    } else if (argv[0] == "hnova") {
        if (argv.size() == 3 && isNumber(argv[1]) && isNumber(argv[2])) {
            *winInfo << "\nComando 'hnova' com argumentos [" << argv[1] << " " << argv[2] << "]\n";
            if (!createHabitacao(stoi(argv[1]), stoi(argv[2])))
                *winInfo << "\nDimensoes invalidas!\n";
            return true;
        } else {
            *winInfo << "\nComando 'hnova' invalido - hnova <num linhas> <num colunas>\n";
        }
    } else if (argv[0] == "hrem") {
        if (argv.size() == 1) {
            *winInfo << "\nComando 'hrem'\n";
            deleteHabitacao();
            return true;
        } else {
            *winInfo << "\nComando 'hrem' invalido - hrem\n";
        }
    } else if (argv[0] == "znova") {
        if (argv.size() == 3 && isNumber(argv[1]) && isNumber(argv[2])) {
            *winInfo << "\nComando 'znova' com argumentos [" << argv[1] << " " << argv[2] << "]\n";

            if (!checkHabitacao()) return true;

            int x = stoi(argv[1]);
            int y = stoi(argv[2]);

            if (!habitacao->addZona(x, y)) {
                *winInfo << "\nPosicao invalida!\n";
                return true;
            }

            *winInfo << "\nZona adicionada com sucesso!\n"
                     << "ID: " << habitacao->getZona(x, y)->getId() << "\n"
                     << "Posicao: " << x << " " << y << "\n";
            return true;
        } else {
            *winInfo << "\nComando 'znova' invalido - znova <linha> <coluna>\n";
        }
    } else if (argv[0] == "zrem") {
        if (argv.size() == 2 && isNumber(argv[1])) {
            *winInfo << "\nComando 'zrem' com argumento " << argv[1] << "\n";

            if (!checkHabitacao()) return true;

            int id = stoi(argv[1]);

            if (!habitacao->removeZona(id)) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            *winInfo << "\nZona de ID " << id << " removida com sucesso!\n";
            return true;
        } else {
            *winInfo << "\nComando 'zrem' invalido - zrem <ID zona>\n";
        }

    } else if (argv[0] == "zlista") {
        if (argv.size() == 1) {
            *winInfo << "\n 'zlista'\n";

            if (!checkHabitacao()) return true;

            Zona ***listaZonas = habitacao->getZonas();
            int wide = habitacao->getWide();
            int height = habitacao->getHeight();

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < wide; j++) {
                    Zona *zona = listaZonas[i][j];

                    if (!zona) continue;

                    int aparelhos = 0;
                    int sensores = 0;
                    int processadores = 0;

                    for (const auto &componente: zona->getComponentes()) {
                        char type = componente->getLetterID();

                        switch (type) {
                            case 'a':
                                aparelhos++;
                                break;
                            case 's':
                                sensores++;
                                break;;
                            case 'p':
                                processadores++;
                                break;
                        }
                    }

                    *winInfo << "\nZona '" << zona->getId() << "'\n";
                    *winInfo << "Aparelhos: " << aparelhos << "\n";
                    *winInfo << "Sensores: " << sensores << "\n";
                    *winInfo << "Processadores: " << processadores << "\n";
                }
            }

            return true;
        } else {
            *winInfo << "\nComando 'zlista' invalido - zlista\n";
        }

        // Comandos para as zonas
    } else if (argv[0] == "zcomp") {
        if (argv.size() == 2 && isNumber(argv[1])) {
            *winInfo << "\nComando 'zcomp' com argumento " << argv[1] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            *winInfo << "\nComponentes da zona '" << zona->getId() << "':\n";
            for (const auto &componente: zona->getComponentes()) {
                char type = componente->getLetterID();
                string typeText;

                switch (type) {
                    case 'a':
                        typeText = "Aparelho";
                        break;
                    case 's':
                        typeText = "Sensor";
                        break;;
                    case 'p':
                        typeText = "Processador";
                        break;
                }

                *winInfo << "\nComponente: " << componente->getId() << "'\n"
                        << componente->toString()
                        << "\n";
            }

            return true;
        } else {
            *winInfo << "\nComando 'zcomp' invalido - zcomp <ID zona>\n";
        }
    } else if (argv[0] == "zprops") {
        if (argv.size() == 2 && isNumber(argv[1])) {
            *winInfo << "\nComando 'zprops' com argumento " << argv[1] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "Zona nao encontrada!\n";
                return true;
            }

            *winInfo << "\nPropriedades da zona '" << zona->getId() << "':\n";

            for (const auto &propriedade: zona->getPropriedades()) {
                *winInfo << "Propriedade '" << propriedade->getName() << "'\n";
                *winInfo << "Valor: " << propriedade->getValue() << "\n\n";
            }

            return true;
        } else {
            *winInfo << "\nComando 'zprops' invalido - zprops <ID zona>\n";
        }
    } else if (argv[0] == "pmod") {
        if (argv.size() == 4 && isNumber(argv[1]) && isNumber(argv[3]) && !isNumber(argv[2])) {
            *winInfo << "\nComando 'pmod' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "]\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            if (!zona->setPropriedade(argv[2], stoi(argv[3]))) {
                *winInfo << "\nPropriedade nao encontrada!\n";
                return true;
            }

            return true;
        } else {
            *winInfo << "\nComando 'pmod' invalido - pmod <ID zona> <name> <value>\n";
        }
    } else if (argv[0] == "cnovo") {
        if (argv.size() == 4 && isNumber(argv[1]) && (argv[2] == "s" || argv[2] == "p" || argv[2] == "a") &&
            !isNumber(argv[3])) {
            *winInfo << "\nComando 'cnovo' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            TipoComponente tipoComponente;

            switch (argv[2][0]) {
                case 's':
                    tipoComponente = TipoComponente::SENSOR;
                    break;
                case 'p':
                    tipoComponente = TipoComponente::PROCESSADOR;
                    break;
                case 'a':
                    tipoComponente = TipoComponente::APARELHO;
                    break;
            }

            int id = zona->getIdCounter();

            switch (tipoComponente) {
                case TipoComponente::SENSOR:
                    if (zona->addComponente(
                            SensorFactory::createSensor(SensorFactory::stringToTipoSensor(argv[3]), id, *zona)))
                        *winInfo << "\nFoi adicionado um sensor\n" << zona->getComponente(id)->toString() << '\n';
                    break;
                case TipoComponente::PROCESSADOR:
                    if (zona->addComponente(new Processador(id, argv[3])))
                        *winInfo << "\nFoi adicionado um processador\n" << zona->getComponente(id)->toString() << '\n';
                    break;
                case TipoComponente::APARELHO:
                    if (zona->addComponente(
                            AparelhoFactory::createAparelho(AparelhoFactory::stringToTipoeAparelho(argv[3]), id,
                                                            *zona)))
                        *winInfo << "\nFoi adicionado um aparelho\n" << zona->getComponente(id)->toString() << '\n';
                    break;
                default:
                    break;
            }

            return true;
        } else {
            *winInfo << "\nComando 'cnovo' invalido - cnovo <ID zona> <s | p | a> <tipo | comando>\n";
        }
    } else if (argv[0] == "crem") {
        if (argv.size() == 4 && isNumber(argv[1]) && (argv[2] == "s" || argv[2] == "p" || argv[2] == "a") &&
            isNumber(argv[3])) {
            *winInfo << "\nComando 'crem' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            zona->removeComponente(argv[2][0], stoi(argv[3]));

            return true;
        } else {
            *winInfo << "\nComando 'crem' invalido - crem <ID zona> <s | p | a> <ID>\n";
        }

        // Comandos para os processadores
    } else if (argv[0] == "rnova") {
        if (argv.size() >= 6 && argv.size() <= 7 && isNumber(argv[1]) && isNumber(argv[2]) && !isNumber(argv[3]) &&
            isNumber(argv[4]) &&
            isNumber(argv[5])) {
            *winInfo << "\nComando 'rnova' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << " "
                     << argv[4] << " " << argv[5] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            auto processador = (Processador *) zona->getComponente(stoi(argv[2]));
            if (!processador) {
                *winInfo << "\nProcessador nao encontrado!\n";
                return true;
            }

            auto sensor = (Sensor *) zona->getComponente(stoi(argv[4]));
            if (!sensor) {
                *winInfo << "\nSensor nao encontrado!\n";
                return true;
            }

            Regra *regra;

            if (argv.size() == 6)
                regra = new Regra(idCount++, Regra::stringToOperacao(argv[3]), sensor, stoi(argv[5]));
            else if (argv.size() == 7)
                regra = new Regra(idCount++, Regra::stringToOperacao(argv[3]), sensor, stoi(argv[5]), stoi(argv[6]));


            if (!regra) {
                *winInfo << "\nErro na criacao da regra!\n";
                return true;
            }

            *winInfo << "\nRegra criada com sucesso!\n";
            *winInfo << regra->toString() << "\n";

            processador->addRegra(regra);

            return true;
        } else {
            *winInfo
                    << "\nComando 'rnova' invalido - rnova <ID zona> <ID proc. regras> <regra> <ID sensor> [param1] (opcional)[param2]\n";
        }
    } else if (argv[0] == "pmuda") {
        if (argv.size() == 4 && isNumber(argv[1]) && isNumber(argv[2]) && !isNumber(argv[3])) {
            *winInfo << "\nComando 'pmuda' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            auto processador = (Processador *) zona->getComponente(stoi(argv[2]));
            if (!processador) {
                *winInfo << "\nProcessador nao encontrado!\n";
                return true;
            }

            processador->setComando(argv[3]);
            *winInfo << "\nComando alterado com sucesso!\n"
                     << processador->toString()
                     << "\n";

            return true;
        } else {
            *winInfo << "\nComando 'pmuda' invalido - pmuda <ID zona> <ID proc. regras> <novo comando>\n";
        }
    } else if (argv[0] == "rlista") {
        if (argv.size() == 3 && isNumber(argv[1]) && isNumber(argv[2])) {
            *winInfo << "\nComando 'rlista' com argumentos [" << argv[1] << " " << argv[2] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            auto processador = (Processador *) zona->getComponente(stoi(argv[2]));
            if (!processador) {
                *winInfo << "\nProcessador nao encontrado!\n";
                return true;
            }

            *winInfo << "\nRegras do processador:\n";

            for (const auto &regra: processador->getRegras()) {
                *winInfo << regra->toString() << '\n';
            }

            return true;
        } else {
            *winInfo << "\nComando 'rlista' invalido - rlista <ID zona> <ID proc. regras>\n";
        }
    } else if (argv[0] == "rrem") {
        if (argv.size() == 4 && isNumber(argv[1]) && isNumber(argv[2]) && isNumber(argv[3])) {
            *winInfo << "\nComando 'rrem' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";

            if (!checkHabitacao()) return true;

            Zona *zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            auto processador = (Processador *) zona->getComponente(stoi(argv[2]));
            if (!processador) {
                *winInfo << "\nProcessador nao encontrado!\n";
                return true;
            }

            processador->removeRegra(stoi(argv[3]));
            *winInfo << "\nRegra removida com sucesso!\n"
                     << processador->toString()
                     << '\n';

            return true;
        } else {
            *winInfo << "\nComando 'rrem' invalido - rrem <ID zona> <ID proc. regras> <ID regra>\n";
        }
    } else if (argv[0] == "asoc") {
        if (argv.size() == 4 && isNumber(argv[1]) && isNumber(argv[2]) && isNumber(argv[3])) {
            *winInfo << "\nComando 'asoc' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";

            if (!checkHabitacao()) return true;

            auto zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            auto processador = (Processador *) zona->getComponente(stoi(argv[2]));
            if (!processador) {
                *winInfo << "\nProcessador nao encontrado!\n";
                return true;
            }

            auto aparelho = (Aparelho *) zona->getComponente(stoi(argv[3]));
            if (!aparelho) {
                *winInfo << "\nAparelho nao encontrado!\n";
                return true;
            }

            processador->addAparelho(aparelho);
            *winInfo << "\nAparelho associado com sucesso!\n"
                     << processador->toString()
                     << "\n";

            return true;
        } else {
            *winInfo << "\nComando 'asoc' invalido - asoc <ID zona> <ID proc. regras> <ID aparelho>\n";
        }
    } else if (argv[0] == "ades") {
        if (argv.size() == 4 && isNumber(argv[1]) && isNumber(argv[2]) && isNumber(argv[3])) {
            *winInfo << "\nComando 'ades' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";

            if (!checkHabitacao()) return true;

            auto zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            auto processador = (Processador *) zona->getComponente(stoi(argv[2]));
            if (!processador) {
                *winInfo << "\nProcessador nao encontrado!\n";
                return true;
            }

            auto aparelho = (Aparelho *) zona->getComponente(stoi(argv[3]));
            if (!aparelho) {
                *winInfo << "\nAparelho nao encontrado!\n";
                return true;
            }

            processador->removeAparelho(aparelho->getNumId());
            *winInfo << "\nAparelho desassociado com sucesso!\n"
                     << processador->toString()
                     << "\n";

            return true;
        } else {
            *winInfo << "\nComando 'ades' invalido - ades <ID zona> <ID proc. regras> <ID aparelho>\n";
        }

        // Comandos para os aparelhos
    } else if (argv[0] == "acom") {
        if (argv.size() == 4 && isNumber(argv[1]) && isNumber(argv[2]) && !isNumber(argv[3])) {
            *winInfo << "\nComando 'acom' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";

            if (!checkHabitacao()) return true;

            auto zona = habitacao->getZona(stoi(argv[1]));
            if (!zona) {
                *winInfo << "\nZona nao encontrada!\n";
                return true;
            }

            auto aparelho = (Aparelho *) zona->getComponente(stoi(argv[2]));
            if (!aparelho) {
                *winInfo << "\nAparelho nao encontrado!\n";
                return true;
            }

            aparelho->readCommand(argv[3]);
            *winInfo << "\nComando executado com sucesso!\n"
                     << aparelho->toString()
                     << "\n";

            return true;
        } else {
            *winInfo << "\nComando 'acom' invalido - acom <ID zona> <ID aparelho> <comando>\n";
        }

        // Comandos para copiar/recuperar dos processadores
    } else if (argv[0] == "psalva") {
        if (argv.size() == 4 && isNumber(argv[1]) && isNumber(argv[2]) && !isNumber(argv[3])) {
            *winInfo << "\nComando 'psalva' com argumentos [" << argv[1] << " " << argv[2] << " " << argv[3] << "\n";

            if (!checkHabitacao()) return true;

            saveProcessadorState(stoi(argv[1]), stoi(argv[2]), argv[3]);

            auto zona = habitacao->getZona(stoi(argv[1]));
            auto processador = (Processador *) zona->getComponente(stoi(argv[2]));

            *winInfo << "\nProcessador salvo com sucesso!\n"
                     << zona->toString()
                     << processador->toString()
                     << "\n";


            return true;
        } else {
            *winInfo << "\nComando 'psalva' invalido - psalva <ID zona> <ID proc. regras> <name>\n";
        }
    } else if (argv[0] == "prepoe") {
        if (argv.size() == 2 && !isNumber(argv[1])) {
            *winInfo << "Comando 'prepoe' " << argv[1] << "\n";

            if (!loadProcessadorState(argv[1])) {
                *winInfo << "\nProcessador nao encontrado!\n";
            }

            loadProcessadorState(argv[3]);

            return true;
        } else {
            *winInfo << "\nComando 'prepoe' invalido: Nao tem argumentos\n";
        }
    } else if (argv[0] == "prem") {
        if (argv.size() == 2 && !isNumber(argv[1])) {
            *winInfo << "\nComando 'prem' com argumento " << argv[1] << "\n";

            deleteProcessadorState(argv[1]);

            return true;
        } else {
            *winInfo << "\nComando 'prem' invalido - prem <name>\n";
        }
    } else if (argv[0] == "plista") {
        if (argv.size() == 1) {
            *winInfo << "\nComando 'plista'\n";

            for (const auto &processador: getProcessadoresStates())
                *winInfo << "Nome: " << processador.first
                         << "Id Processador: " << processador.second.second->getNumId()
                         << "Id Zona: " << processador.second.first
                         << '\n';

            return true;
        } else {
            *winInfo << "\nComando 'plista' invalido - plista\n";
        }

        // Comandos para o simulador
    } else if (argv[0] == "exec") {
        if (argv.size() == 2 && !isNumber(argv[1])) {
            *winInfo << "\nComando 'exec' com argumento " << argv[1] << "\n";
            if (!readFile(argv[1])) {
                *winInfo << "\nFicheiro nao encontrado!\n";
            }
            return true;
        } else {
            *winInfo << "\nComando 'exec' invalido - exec <name de ficheiro>\n";
        }
    } else if (argv[0] == "sair") {
        if (argv.size() == 1) {
            *winInfo << "\nComando 'sair'\n";
            stop();
            return true;
        } else {
            *winInfo << "\nComando 'sair' invalido - sair";
        }
    }

    return false;
}

bool Simulador::readFile(const string &filename) {
    fstream file(FILE_PATH + filename, ios::in);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream cmd(line);
            if (!validateCommand(cmd)) {
                *winInfo << "\nComando invalido!\n";
            }
        }

        return true;
    }

    return false;
}

bool Simulador::checkHabitacao() {
    if (!habitacao) {
        *winInfo << "\nNao existe habitacao!\n\n";
        return false;
    }

    return true;
}

bool Simulador::createHabitacao(int wide, int heigth) {
    if (wide < 2 || wide > 4 || heigth < 2 || heigth > 4) return false;

    deleteHabitacao();

    habitacao = new Habitacao(wide, heigth);
    *winInfo << "\nHabitacao criada com sucesso!\n"
             << "Dimensoes:\n\tLargura: " << wide << "\n\tAltura: " << heigth << "\n\n";

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

    *winInfo << "\nHabitacao removida com sucesso!\n\n";
}

Simulador::~Simulador() {
    deleteHabitacao();
    delete winInfo;
    delete winConsole;
    delete winView;
}

void Simulador::saveProcessadorState(int idZona, int idProcessador, const string &name) {
    processadorStatesList[name] = pair<int, Processador *>(idZona,
                                                           (Processador *) habitacao->getZona(idZona)->getComponente(
                                                                   idProcessador));
}

bool Simulador::loadProcessadorState(const string &name) {
    auto it = processadorStatesList.find(name);
    if (it == processadorStatesList.end()) return false;

    auto zona = habitacao->getZona(it->second.first);
    if (!zona) return false;

    auto processador = (Processador *) zona->getComponente(it->second.second->getNumId());
    if (!processador) return false;

    *processador = *it->second.second;
    return true;
}

void Simulador::deleteProcessadorState(const string &name) {
    processadorStatesList.erase(name);
}

vector<pair<string, pair<int, Processador *>>> Simulador::getProcessadoresStates() {
    vector<pair<string, pair<int, Processador *>>> processadores;

    for (const auto &processador: processadorStatesList)
        processadores.push_back(pair<string, pair<int, Processador *>>(processador.first, processador.second));

    return processadores;
}
