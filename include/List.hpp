#pragma once
#include <iostream>
#include "Element.hpp"

using namespace std;

template <class TIPO>
class List {
private:
    Element<TIPO>* pPrimeiro;
    Element<TIPO>* pUltimo;

public:
    List();
    ~List();
    void incluir(TIPO* p);
    void limpar();
    void imprimir();
    void remover(TIPO* p);

	Element<TIPO>* getPrimeiro() const { return pPrimeiro; }
	Element<TIPO>* getUltimo() const { return pUltimo; }

public:
    // Classe aninhada iterator, para o método percorrer
    class Iterator {
    private:
		Element<TIPO>* pAtual;
    public:
		//++it
        Iterator& operator++() {
			if (pAtual) {
				pAtual = pAtual->getProximo();
			}
			return *this;
		}

        bool operator != (const Iterator& other) const {
            return pAtual != other.pAtual;
        }

		bool operator == (const Iterator& other) const {
			return pAtual == other.pAtual;
		}

		Iterator begin() const {
			return Iterator(pPrimeiro);
		}

		Iterator end() const {
			return Iterator(NULL);
		}
    };
};

template <class TIPO>
List<TIPO>::List() : pPrimeiro(NULL), pUltimo(NULL) {}

template <class TIPO>
List<TIPO>::~List() {
    limpar();
}

template <class TIPO>
void List<TIPO>::incluir(TIPO* p) {
    if (p) {
        Element<TIPO>* pNovo = new Element<TIPO>();
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
void List<TIPO>::limpar() {
    Element<TIPO>* pAux = pPrimeiro;
    while (pAux != NULL) {
        pPrimeiro = pAux->getProximo();
        delete pAux;
        pAux = pPrimeiro;
    }
    pUltimo = NULL;
}

template <class TIPO>
void List<TIPO>::imprimir() {
    Element<TIPO>* pAux = pPrimeiro;
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
void List<TIPO>::remover(TIPO* p) {
	Element<TIPO>* pAux = pPrimeiro;
	Element<TIPO>* pAnterior = NULL;
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