#ifndef PROPRIEDADE_H
#define PROPRIEDADE_H

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
