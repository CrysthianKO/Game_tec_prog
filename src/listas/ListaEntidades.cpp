#include "ListaEntidades.hpp"
#include <iostream>

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::incluir(Entidade* pE) {
    LEs.incluir(pE);
}

void ListaEntidades::percorrer() {
    // Lógica para iterar sobre a lista LEs
}