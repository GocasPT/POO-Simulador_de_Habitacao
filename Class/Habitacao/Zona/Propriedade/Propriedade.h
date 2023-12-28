#ifndef PROPRIEDADE_H
#define PROPRIEDADE_H

#define TEMPERATURA_STR "Temperatura"
#define LUZ_STR "Luz"
#define RADIACAO_STR "Radiacao"
#define VIBRACAO_STR "Vibracao"
#define HUMIDADE_STR "Humidade"
#define FUMO_STR "Fumo"
#define SOM_STR "Som"

#include <string>

using std::string;

//TODO [Meta 2]: Virutalizar a class (hirearquia)
class Propriedade {
protected:
    string name;
    int value;
    const string unit;
    const int minValue;
    const bool isPercentage;

public:
    Propriedade(const string &name, const string &unit, int minValue, bool isPercentage);

    string getName() const;

    int getValue() const;

    void setValor(int value);
};


#endif //PROPRIEDADE_H
