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

class Propriedade {
protected:
    const string name;
    double value;
    const string unit;
    const double maxValue, minValue;
    const bool haveMax, haveMin;
    const bool isPercentage;

public:
    Propriedade(const string &name, const string &unit, double valueDefault, bool isPercentage = true,
                double minValue = 0.0, double maxValue = 0.0, bool haveMin = false, bool haveMax = false);

    string getName() const;

    double getValue() const;

    void setValor(double value);

    virtual string toString() const;
};


#endif //PROPRIEDADE_H
