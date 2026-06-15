#include "entities/Ente.hpp"

#include "managers/GraphicsManager.hpp"
#include "managers/TimeManager.hpp"

int Ente::cont_id(0);
GraphicsManager* Ente::pGM = NULL;
TimeManager* Ente::pTM = NULL;

Ente::Ente() : mId(cont_id++) {
  cout << "Ent ID: " << mId << " criada." << endl;
}
Ente::~Ente() { cout << "Ent ID: " << mId << " destruido." << endl; }

void Ente::setGM(GraphicsManager* pG) {
  if (!pG) {
    throw std::invalid_argument("ponteiro gerenciador grafico nulo!");
  }
  pGM = pG;
}

void Ente::setTM(TimeManager* pT) {
  if (!pT) {
    throw std::invalid_argument("Ponteiro Gerenciador de Timer NULO!");
  }
  pTM = pT;
}

int Ente::getId() const { return mId; }
