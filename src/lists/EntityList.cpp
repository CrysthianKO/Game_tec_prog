#include "EntityList.hpp"
#include <iostream>

EntityList::EntityList() {}

EntityList::~EntityList() {}

void EntityList::incluir(Entity* pE) {
    LEs.incluir(pE);
}

void EntityList::percorrer() {
    //percorre a lista e faz as entidades executarem suas ações
}