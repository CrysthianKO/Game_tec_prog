#include "ListaEntidades.hpp"
#include <iostream>

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::incluir(Entidade* pE) {
    LEs.incluir(pE);
}

void ListaEntidades::percorrer() {
    //percorre a lista e faz as entidades executarem suas ações
}