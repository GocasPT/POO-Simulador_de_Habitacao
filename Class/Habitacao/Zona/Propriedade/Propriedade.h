#ifndef PROPRIEDADE_H
#define PROPRIEDADE_H

#include <string>

class Propriedade {
    std::string name;
    int value;

public:
    Propriedade(std::string name, int value);

    std::string getName() const;

    int getValue() const;

    void setValor(int valor);

    ~Propriedade();
};


#endif //PROPRIEDADE_H
