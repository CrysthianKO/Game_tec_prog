#pragma once
#include "List.hpp"

class Entity;

class EntityList {
private:
    List<Entity> LEs;

public:
    EntityList();
    ~ListaEntidades(){}
    EntityList();

    void incluir(Entity* pE);
    void percorrer();
};