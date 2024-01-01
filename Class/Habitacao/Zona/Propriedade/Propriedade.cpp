#include "Propriedade.h"

Propriedade::Propriedade(const string &name, const string &unit, int minValue, bool isPercentage)
        : unit(unit), minValue(minValue),
          isPercentage(isPercentage) {
    this->name = name;
    value = 0; //TODO: radnom number
}

string Propriedade::getName() const { return name; }

int Propriedade::getValue() const { return value; }

void Propriedade::setValor(int value) {
    if (value < minValue)
        this->value = minValue;
    else if (isPercentage && value > 100)
        this->value = 100;
    else
        this->value = value;
}
