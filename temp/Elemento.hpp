#pragma once
#include <SFML/Graphics.hpp>

/*Nó de lista encadeada simples*/

template <class TIPO>
class Elemento {
private:
    Elemento<TIPO>* pProx;
    TIPO* pInfo;

public:
    Elemento();
    ~Elemento();

    void setProximo(Elemento<TIPO>* pE) { pProx = pE; }
    Elemento<TIPO>* getProximo() const { return pProx; }

    void setInfo(TIPO* pI) { pInfo = pI; }
    TIPO* getInfo() const { return pInfo; }
};

// Implementação no header por ser template
template <class TIPO>
Elemento<TIPO>::Elemento() : pProx(NULL), pInfo(NULL) {}

template <class TIPO>
Elemento<TIPO>::~Elemento() {}