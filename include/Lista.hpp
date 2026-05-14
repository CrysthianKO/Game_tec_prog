#pragma once

/*Código gerado por ia*/

#include "Elemento.hpp"

template <class TL>
class Lista {
private:
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;

public:
    Lista();
    ~Lista();

    void incluir(TL* p);
    void limpar();
    // ... outros métodos do diagrama
};

template <class TL>
Lista<TL>::Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

template <class TL>
Lista<TL>::~Lista() {
    limpar();
}

template <class TL>
void Lista<TL>::incluir(TL* p) {
    if (p) {
        Elemento<TL>* pNovo = new Elemento<TL>();
        pNovo->setInfo(p);

        if (!pPrimeiro) {
            pPrimeiro = pNovo;
            pUltimo = pNovo;
        }
        else {
            pUltimo->setProx(pNovo);
            pUltimo = pNovo;
        }
    }
}

template <class TL>
void Lista<TL>::limpar() {
    Elemento<TL>* pAux = pPrimeiro;
    while (pAux != nullptr) {
        pPrimeiro = pAux->getProximo();
        delete pAux;
        pAux = pPrimeiro;
    }
    pUltimo = nullptr;
}