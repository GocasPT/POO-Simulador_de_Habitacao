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

//TODO [Meta 2]: Virutalizar a class (hirearquia)
class Propriedade {
protected:
    std::string name;
    int value;
    const std::string unit;
    const int minValue;
    const bool isPercentage;

public:
    Propriedade(const std::string &name, const std::string &unit, int minValue, bool isPercentage);

    std::string getName() const;

    int getValue() const;

    void setValor(int value);
};


#endif //PROPRIEDADE_H
