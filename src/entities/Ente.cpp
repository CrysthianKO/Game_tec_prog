#include "entities/Ente.hpp"

#include "managers/GraphicsManager.hpp"

int Ente::cont_id(0);
GraphicsManager* Ente::pGM = NULL;

Ente::Ente() : mId(cont_id++) {
  cout << "Ent ID: " << mId << " criada." << endl;
}
Ente::~Ente() { cout << "Ent ID: " << mId << " destruido." << endl; }

void Ente::setGM(GraphicsManager* pG) {
  if (!pG) {
    throw std::invalid_argument("Ponteiro Gerenciador Grafico NULO!");
  }
  pGM = pG;
}

int Ente::getId() const { return mId; }
