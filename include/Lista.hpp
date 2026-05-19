#pragma once
#include <iostream>
#include "Elemento.hpp"

using namespace std;

template <class TIPO>
class Lista {
private:
    Elemento<TIPO>* pPrimeiro;
    Elemento<TIPO>* pUltimo;

public:
    Lista();
    ~Lista();

    void incluir(TIPO* p);
    void limpar();
    void imprimir();
    void remover(TIPO* p);

	Elemento<TIPO>* getPrimeiro() const { return pPrimeiro; }
	Elemento<TIPO>* getUltimo() const { return pUltimo; }

public:
    // Classe aninhada iterator, para o método percorrer
    class Iterator {

    };
};

template <class TIPO>
Lista<TIPO>::Lista() : pPrimeiro(NULL), pUltimo(NULL) {}

template <class TIPO>
Lista<TIPO>::~Lista() {
    limpar();
}

template <class TIPO>
void Lista<TIPO>::incluir(TIPO* p) {
    if (p) {
        Elemento<TIPO>* pNovo = new Elemento<TIPO>();
        pNovo->setInfo(p);

        if (!pPrimeiro) {
            pPrimeiro = pNovo;
            pUltimo = pNovo;
        }
        else {
            pUltimo->setProximo(pNovo);
            pUltimo = pNovo;
        }
    }
    else {
		cout << "ERRO: Ponteiro nulo não pode ser adicionado à lista." << endl;
    }
}

template <class TIPO>
void Lista<TIPO>::limpar() {
    Elemento<TIPO>* pAux = pPrimeiro;
    while (pAux != NULL) {
        pPrimeiro = pAux->getProximo();
        delete pAux;
        pAux = pPrimeiro;
    }
    pUltimo = NULL;
}

template <class TIPO>
void Lista<TIPO>::imprimir() {
    Elemento<TIPO>* pAux = pPrimeiro;
    while (pAux != NULL) {
        // Assume-se que TIPO (o objeto guardado) tem alguma forma de ser impresso
        // Se pNovo->setInfo(p) recebe um ponteiro, getInfo() deve retornar TIPO*
        if (pAux->getInfo()) {
            cout << *(pAux->getInfo()) << " ";
        }
        pAux = pAux->getProximo();
    }
    cout << endl;
}

template <class TIPO>
void Lista<TIPO>::remover(TIPO* p) {
	Elemento<TIPO>* pAux = pPrimeiro;
	Elemento<TIPO>* pAnterior = NULL;
	while (pAux != NULL) {
		if (pAux->getInfo() == p) {
			if (pAnterior) {
				pAnterior->setProximo(pAux->getProximo());
			}
			else {
				pPrimeiro = pAux->getProximo();
			}
			if (pAux == pUltimo) {
				pUltimo = pAnterior;
			}
			delete pAux;
			return;
		}
		pAnterior = pAux;
		pAux = pAux->getProximo();
	}
}