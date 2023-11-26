#include "Propriedade.h"

Propriedade::Propriedade(const std::string &name, const std::string &unit, int minValue, bool isPercentage)
        : unit(unit), minValue(minValue),
          isPercentage(isPercentage) {
    this->name = name;
    value = 0;
}

std::string Propriedade::getName() const { return name; }
int Propriedade::getValue() const { return value; }

void Propriedade::setValor(int value) {
    if (value < minValue)
        value = minValue;
    else if (isPercentage && value > 100)
        value = 100;
    else
        this->value = value;
}
