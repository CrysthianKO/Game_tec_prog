#pragma once
#include <iostream>
<<<<<<< HEAD
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
=======

#include "Element.hpp"

using namespace std;
template <class TYPE>
class List {
 private:
  Element<TYPE>* pFirst;
  Element<TYPE>* pLast;

 public:
  List();
  ~List();

  void include(TYPE* p);
  void wipe();
  void print();
  void remove(TYPE* p);

  Element<TYPE>* getFirst() const { return pFirst; }
  Element<TYPE>* getLast() const { return pLast; }

 public:
  class Iterator {
   private:
    Element<TYPE>* pCurrent;

   public:
    Iterator(Element<TYPE>* pNode) : pCurrent(pNode) {}
    Iterator() : pCurrent(NULL) {}
    //++it
    Iterator& operator++() {
      if (pCurrent) {
        pCurrent = pCurrent->getNext();
      }
      return *this;
    }

    TYPE* operator*() const { return pCurrent ? pCurrent->getInfo() : NULL; }

    bool operator!=(const Iterator& other) const {
      return pCurrent != other.pCurrent;
    }

    bool operator==(const Iterator& other) const {
      return pCurrent == other.pCurrent;
    }
  };

  Iterator begin() const { return Iterator(pFirst); }

  Iterator end() const { return Iterator(NULL); }
};

template <class TYPE>
List<TYPE>::List() : pFirst(NULL), pLast(NULL) {}

template <class TYPE>
List<TYPE>::~List() {
  wipe();
}

// Aqui matamos um desing pattern o padrao iterator
template <class TYPE>
void List<TYPE>::include(TYPE* p) {
  if (p) {
    Element<TYPE>* pNew = new Element<TYPE>();
    pNew->setInfo(p);

    if (!pFirst) {
      pFirst = pNew;
      pLast = pNew;
    } else {
      pLast->setNext(pNew);
      pLast = pNew;
    }
  } else {
    cerr << "ERRO: Ponteiro nulo não pode ser adicionado à lista." << endl;
  }
}

template <class TYPE>
void List<TYPE>::wipe() {
  Element<TYPE>* pAux = pFirst;
  while (pAux != NULL) {
    pFirst = pAux->getNext();
    delete pAux;
    pAux = pFirst;
  }
  pLast = NULL;
}

template <class TYPE>
void List<TYPE>::print() {
  Element<TYPE>* pAux = pFirst;
  while (pAux != NULL) {
    // Assume-se que TIPO (o objeto guardado) tem alguma forma de ser impresso
    // Se pNovo->setInfo(p) recebe um ponteiro, getInfo() deve retornar TIPO*
    if (pAux->getInfo()) {
      cout << *(pAux->getInfo()) << " ";
    }
    pAux = pAux->getNext();
  }
  cout << endl;
}

template <class TYPE>
void List<TYPE>::remove(TYPE* p) {
  Element<TYPE>* pAux = pFirst;
  Element<TYPE>* pPrevious = NULL;
  while (pAux != NULL) {
    if (pAux->getInfo() == p) {
      if (pPrevious) {
        pPrevious->setNext(pAux->getNext());
      } else {
        pFirst = pAux->getNext();
      }
      if (pAux == pLast) {
        pLast = pPrevious;
      }
      delete pAux;
      return;
    }
    pPrevious = pAux;
    pAux = pAux->getNext();
  }
}
>>>>>>> 4795ee6bbd3d3fcd1a4b5ea5a06f8eca20a8fb09
