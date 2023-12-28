#include "Regra.h"

using std::cout;


//falta os argumentos do componente
Regra::Regra(int id) : Componente( , ){

};

void Regra::readSensor() {
    int valorLido = sensor.read(); //sei que não é read, mas não estou a perceber o que é para meter
    cout << "Valor lido do sensor: " << valorLido << std::endl;
}

bool Regra::validate() {
    int valorLido = sensor.read(); //sei que não é read, mas não estou a perceber o que é para meter

    switch (operacao) {
        case igual_a:
            return (valorLido == valor1);

        case menor_que:
            return (valorLido < valor1);

        case maior_que:
            return (valorLido > valor1);

        case entre:
            return (valorLido >= valor1 && valorLido <= valor2);

        case fora:
            return (valorLido < valor1 || valorLido > valor2);

        default:
            std::cerr << "Operacao invalida." << std::endl;
            return false;
    }
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