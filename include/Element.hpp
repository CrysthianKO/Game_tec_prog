#pragma once
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