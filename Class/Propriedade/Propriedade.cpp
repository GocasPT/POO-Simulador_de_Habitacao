#include <sstream>
#include "Propriedade.h"

using std::ostringstream;

Propriedade::Propriedade(const string &name, const string &unit, double valueDefault, bool isPercentage,
                         double minValue,
                         double maxValue, bool haveMin, bool haveMax)
        : name(name), unit(unit), minValue(minValue), maxValue(maxValue), haveMin(haveMin),
                                         haveMax(haveMax), isPercentage(isPercentage) {
    value = valueDefault;
}

string Propriedade::getName() const { return name; }

double Propriedade::getValue() const { return value; }

void Propriedade::setValor(double value) {
    if (isPercentage) {
        if (value > 100) value = 100;
        else if (value < 0) value = 0;
        else this->value += value;
    } else {
        if (haveMax && value > maxValue) value = maxValue;
        else if (haveMin && value < minValue) value = minValue;
        else this->value += value;
    }
}

string Propriedade::toString() const {
    ostringstream oss;

    oss << name << ": " << value << unit << "\n";

    return oss.str();
}
