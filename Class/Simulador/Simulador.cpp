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

    std::istringstream comando0("prox");
    validateCommand(comando0);

    std::istringstream comando1("avanca");
    validateCommand(comando1);

    std::istringstream comando2("hnova");
    validateCommand(comando2);

    std::istringstream comando3("hrem");
    validateCommand(comando3);

    std::istringstream comando4("znova");
    validateCommand(comando4);

    std::istringstream comando5("zrem");
    validateCommand(comando5);

    std::istringstream comando6("zlista");
    validateCommand(comando6);

    std::istringstream comando7("zcomp");
    validateCommand(comando7);

    std::istringstream comando8("zprops");
    validateCommand(comando8);

    std::istringstream comando9("pmod");
    validateCommand(comando9);

    std::istringstream comando10("cnovo");
    validateCommand(comando10);

    std::istringstream comando11("crem");
    validateCommand(comando11);

    std::istringstream comando12("rnova");
    validateCommand(comando12);

    std::istringstream comando13("pmuda");
    validateCommand(comando13);

    std::istringstream comando14("rlista");
    validateCommand(comando14);

    std::istringstream comando15("rrem");
    validateCommand(comando15);

    std::istringstream comando16("asoc");
    validateCommand(comando16);

    std::istringstream comando17("ades");
    validateCommand(comando17);

    std::istringstream comando18("acom");
    validateCommand(comando18);

    std::istringstream comando19("psalva");
    validateCommand(comando19);

    std::istringstream comando20("prepoe");
    validateCommand(comando20);

    std::istringstream comando21("prem");
    validateCommand(comando21);

    std::istringstream comando22("plista");
    validateCommand(comando22);

    std::istringstream comando24("exec");
    validateCommand(comando24);

    std::istringstream comando25("sair");
    validateCommand(comando25);



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
    argv.pop_back();

    if (argv[0] == "prox") {
        if (argv.size() == 1) {
            //*winInfo << "Comando 'prox'\n";
            term << "Comando 'prox'\n";
            return true;
        } else {
            //*winInfo << "Comando 'prox' invalido: Nao tem argumentos\n";
            term << "Comando 'prox' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "avanca") {
        if (argv.size() == 2) {
            //*winInfo << "Comando 'avanca'\n";
            term << "Comando 'avanca'\n";
            return true;
        } else {
            //*winInfo << "Comando 'avanca' invalido: Nao tem argumentos\n";
            term << "Comando 'avanca' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "hnova") {
        if (argv.size() == 3) {
            //*winInfo << "Comando 'hnova'\n";
            term << "Comando 'hnova'\n";
            return true;
        } else {
            //*winInfo << "Comando 'hnova' invalido: Nao tem argumentos\n";
            term << "Comando 'hnova' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "hrem") {
        if (argv.size() == 1) {
            //*winInfo << "Comando 'hrem'\n";
            term << "Comando 'hrem'\n";
            return true;
        } else {
            //*winInfo << "Comando 'hrem' invalido: Nao tem argumentos\n";
            term << "Comando 'hrem' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "znova") {
        if (argv.size() == 3) {
            //*winInfo << "Comando 'znova'\n";
            term << "Comando 'znova'\n";
            return true;
        } else {
            //*winInfo << "Comando 'znova' invalido: Nao tem argumentos\n";
            term << "Comando 'znova' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "zrem") {
        if (argv.size() == 2) {
            //*winInfo << "Comando 'zrem'\n";
            term << "Comando 'zrem'\n";
            return true;
        } else {
            //*winInfo << "Comando 'zrem' invalido: Nao tem argumentos\n";
            term << "Comando 'zrem' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "zlista") {
        if (argv.size() == 1) {
            //*winInfo << "Comando 'zlista'\n";
            term << "Comando 'zlista'\n";
            return true;
        } else {
            //*winInfo << "Comando 'zlista' invalido: Nao tem argumentos\n";
            term << "Comando 'zlista' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "zcomp") {
        if (argv.size() == 2) {
            //*winInfo << "Comando 'zcomp'\n";
            term << "Comando 'zcomp'\n";
            return true;
        } else {
            //*winInfo << "Comando 'zcomp' invalido: Nao tem argumentos\n";
            term << "Comando 'zcomp' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "zprops") {
        if (argv.size() == 2) {
            //*winInfo << "Comando 'zprops'\n";
            term << "Comando 'zprops'\n";
            return true;
        } else {
            //*winInfo << "Comando 'zprops' invalido: Nao tem argumentos\n";
            term << "Comando 'zprops' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "pmod") {
        if (argv.size() == 3) {
            //*winInfo << "Comando 'pmod'\n";
            term << "Comando 'pmod'\n";
            return true;
        } else {
            //*winInfo << "Comando 'pmod' invalido: Nao tem argumentos\n";
            term << "Comando 'pmod' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "cnovo") {
        if (argv.size() == 4) {
            //*winInfo << "Comando 'cnovo'\n";
            term << "Comando 'cnovo'\n";
            return true;
        } else {
            //*winInfo << "Comando 'cnovo' invalido: Nao tem argumentos"\n;
            term << "Comando 'cnovo' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "crem") {
        if (argv.size() == 4) {
            //*winInfo << "Comando 'crem'\n";
            term << "Comando 'crem'\n";
            return true;
        } else {
            //*winInfo << "Comando 'crem' invalido: Nao tem argumentos\n";
            term << "Comando 'crem' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "rnova") {
        if (argv.size() == 5) {
            //*winInfo << "Comando 'rnova'\n";
            term << "Comando 'rnova'\n";
            return true;
        } else {
            //*winInfo << "Comando 'rnova' invalido: Nao tem argumentos\n";
            term << "Comando 'rnova' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "pmuda") {
        if (argv.size() == 4) {
            //*winInfo << "Comando 'pmuda'\n";
            term << "Comando 'pmuda'\n";
            return true;
        } else {
            //*winInfo << "Comando 'pmuda' invalido: Nao tem argumentos\n";
            term << "Comando 'pmuda' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "rlista") {
        if (argv.size() == 3) {
            //*winInfo << "Comando 'rlista'\n";
            term << "Comando 'rlista'\n";
            return true;
        } else {
            //*winInfo << "Comando 'rlista' invalido: Nao tem argumentos\n";
            term << "Comando 'rlista' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "rrem") {
        if (argv.size() == 4) {
            //*winInfo << "Comando 'rrem'\n";
            term << "Comando 'rrem'\n";
            return true;
        } else {
            //*winInfo << "Comando 'rrem' invalido: Nao tem argumentos\n";
            term << "Comando 'rrem' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "asoc") {
        if (argv.size() == 4) {
            //*winInfo << "Comando 'asoc'\n";
            term << "Comando 'asoc'\n";
            return true;
        } else {
            //*winInfo << "Comando 'asoc' invalido: Nao tem argumentos"\n;
            term << "Comando 'asoc' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "ades") {
        if (argv.size() == 4) {
            //*winInfo << "Comando 'ades'\n";
            term << "Comando 'ades'\n";
            return true;
        } else {
            //*winInfo << "Comando 'ades' invalido: Nao tem argumentos\n";
            term << "Comando 'ades' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "acom") {
        if (argv.size() == 4) {
            //*winInfo << "Comando 'acom'\n";
            term << "Comando 'acom'\n";
            return true;
        } else {
            //*winInfo << "Comando 'acom' invalido: Nao tem argumentos\n";
            term << "Comando 'acom' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "psalva") {
        if (argv.size() == 4) {
            //*winInfo << "Comando 'psalva'\n";
            term << "Comando 'psalva'\n";
            return true;
        } else {
            //*winInfo << "Comando 'psalva' invalido: Nao tem argumentos\n";
            term << "Comando 'psalva' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "prepoe") {
        if (argv.size() == 2) {
            //*winInfo << "Comando 'prepoe'\n";
            term << "Comando 'prepoe'\n";
            return true;
        } else {
            //*winInfo << "Comando 'prepoe' invalido: Nao tem argumentos\n";
            term << "Comando 'prepoe' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "prem") {
        if (argv.size() == 2) {
            //*winInfo << "Comando 'prem'\n";
            term << "Comando 'prem'\n";
            return true;
        } else {
            //*winInfo << "Comando 'prem' invalido: Nao tem argumentos\n";
            term << "Comando 'prem' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "plista") {
        if (argv.size() == 1) {
            //*winInfo << "Comando 'plista'\n";
            term << "Comando 'plista'\n";
            return true;
        } else {
            //*winInfo << "Comando 'plista' invalido: Nao tem argumentos\n";
            term << "Comando 'plista' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "exec") {
        if (argv.size() == 2) {
            //*winInfo << "Comando 'exec'\n";
            term << "Comando 'exce'\n";
            return true;
        } else {
            //*winInfo << "Comando 'exec' invalido: Nao tem argumentos\n";
            term << "Comando 'exec' invalido: Nao tem argumentos\n";
        }
    }else  if (argv[0] == "sair") {
        if (argv.size() == 1) {
            //*winInfo << "Comando 'sair'\n";
            term << "Comando 'sair'\n";
            return true;
        } else {
            //*winInfo << "Comando 'sair' invalido: Nao tem argumentos\n";
            term << "Comando 'sair' invalido: Nao tem argumentos\n";
        }
    }else
        term<< "Comando invalido!!\n";

    return false;
}

Simulador::~Simulador() {
    delete winView;
    delete winConsole;
    delete winInfo;
    delete winMenu;
}
