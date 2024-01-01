#include <map>
#include <sstream>
#include "Regra.h"

using std::map, std::ostringstream, std::cout;

Regra::Regra(int id, Operacao operacao, Sensor *sensor, int x, int y) : Componente('r', id), sensor(*sensor), operacao(operacao), x(x), y(y){};

Operacao Regra::stringToOperacao(const string &operacao) {
    static const map<string, Operacao> operacaoMap = {
            {"igual_a", Operacao::IGUAL_A},
            {"menor_que", Operacao::MENOR_QUE},
            {"maior_que", Operacao::MAIOR_QUE},
            {"entre", Operacao::ENTRE},
            {"fora", Operacao::FORA},
    };

    auto it = operacaoMap.find(operacao);
    if (it != operacaoMap.end())
        return it->second;

    return Operacao::UNKNOWN;
}

void Regra::readSensor() {
    int valorLido = sensor.getPropriedadeValue(); //sei que não é read, mas não estou a perceber o que é para meter
    cout << "Valor lido do sensor: " << valorLido << std::endl;
}

bool Regra::validate() {
    int valorLido = sensor.getPropriedadeValue(); //sei que não é read, mas não estou a perceber o que é para meter

    switch (operacao) {
        case Operacao::IGUAL_A:
            return (valorLido == x);

        case Operacao::MENOR_QUE:
            return (valorLido < x);

        case Operacao::MAIOR_QUE:
            return (valorLido > x);

        case Operacao::ENTRE:
            return (valorLido >= x && valorLido <= y);

        case Operacao::FORA:
            return (valorLido < x || valorLido > y);

        default:
            std::cerr << "Operacao invalida." << std::endl;
            return false;
    }
}

string Regra::toString() const {
    ostringstream oss;

    string nome;
    switch (operacao) {
        case Operacao::IGUAL_A:
            nome = "igual_a";
            break;
        case Operacao::MENOR_QUE:
            nome = "menor_que";
            break;
        case Operacao::MAIOR_QUE:
            nome = "maior_que";
            break;
        case Operacao::ENTRE:
            nome = "entre";
            break;
        case Operacao::FORA:
            nome = "fora";
            break;
    }

    oss << "Nome: " << nome
        << " Id: " << id
        << " Id Sensor: " << sensor.getId()
        << '\n';

    return oss.str();
}


/* meter na função principal (penso eu)

    Componente componente(1);



    Regra igualA(2);
    Regra menorQue(3);
    Regra entre(4);


    igualA.readSensor();
    cout << "Regra IGUAL_A valida: " << (igualA.validate() ? "Verdadeiro" : "Falso") << std::endl;

    menorQue.readSensor();
    cout << "Regra MENOR_QUE valida: " << (menorQue.validate() ? "Verdadeiro" : "Falso") << std::endl;

    entre.readSensor();
    cout << "Regra ENTRE valida: " << (entre.validate() ? "Verdadeiro" : "Falso") << std::endl;

    return 0;
 */