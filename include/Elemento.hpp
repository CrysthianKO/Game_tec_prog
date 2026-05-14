#pragma once
#include <SFML/Graphics.hpp>

/* Código gerado por ia*/

template <class TE>
class Elemento {
private:
    Elemento<TE>* pProx;
    TE* pInfo;

public:
    Elemento();
    ~Elemento();

    void setProx(Elemento<TE>* pE) { pProx = pE; }
    Elemento<TE>* getProximo() const { return pProx; }

    void setInfo(TE* pI) { pInfo = pI; }
    TE* getInfo() const { return pInfo; }
};

// Implementação no header por ser template
template <class TE>
Elemento<TE>::Elemento() : pProx(nullptr), pInfo(nullptr) {}

template <class TE>
Elemento<TE>::~Elemento() {}