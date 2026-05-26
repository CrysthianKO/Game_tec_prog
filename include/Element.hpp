#pragma once
<<<<<<< HEAD
#include <SFML/Graphics.hpp>

/*Nó de lista encadeada simples*/

template <class TIPO>
class Element {
private:
    Element<TIPO>* pProx;
    TIPO* pInfo;

public:
    Element();
    ~Element();

    void setProximo(Element<TIPO>* pE) { pProx = pE; }
    Element<TIPO>* getProximo() const { return pProx; }

    void setInfo(TIPO* pI) { pInfo = pI; }
    TIPO* getInfo() const { return pInfo; }
};

// Implementação no header por ser template
template <class TIPO>
Element<TIPO>::Element() : pProx(NULL), pInfo(NULL) {}

template <class TIPO>
Element<TIPO>::~Element() {}
=======
#include <cstddef>

template <class TYPE>
class Element {
 private:
  Element<TYPE>* pNext;
  TYPE* pInfo;

 public:
  Element() : pNext(NULL), pInfo(NULL) {}
  ~Element() {}

  void setNext(Element<TYPE>* pE) { pNext = pE; }
  Element<TYPE>* getNext() { return pNext; }

  void setInfo(TYPE* pI) { pInfo = pI; }
  TYPE* getInfo() { return pInfo; }
};
>>>>>>> 4795ee6bbd3d3fcd1a4b5ea5a06f8eca20a8fb09
