#pragma once

/*Código gerado por ia*/

#include "Lista.hpp"
// Supondo que você tenha uma classe Entidade
class Entidade;

class ListaEntidades {
private:
    Lista<Entidade*> LEs; // Composição conforme o diagrama

public:
    ListaEntidades();
    ~ListaEntidades();

    void incluir(Entidade* pE);
    void percorrer();
};