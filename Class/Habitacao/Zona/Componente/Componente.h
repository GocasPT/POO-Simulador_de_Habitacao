#ifndef COMPONENTES_H
#define COMPONENTES_H

enum ComponentType {
    PROCESSADOR,
    APARELHO,
    SENSOR
};

class Componente {
protected:
    int id;
    ComponentType type;

public:
    Componente(int id, ComponentType type);

    int getId() const;

    ComponentType getType() const;

    ~Componente();
};

#endif //COMPONENTES_H
