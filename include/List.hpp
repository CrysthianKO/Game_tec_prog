#pragma once
#include <iostream>

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
