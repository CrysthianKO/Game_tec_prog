#include "entities/ListEntities.hpp"

#include "entities/Entity.hpp"

namespace DinoGame {
namespace Lists {
using namespace Entities;

ListEntities::ListEntities() : lEs() {}

ListEntities::~ListEntities() {
  List<Entity>::Iterator it = lEs.begin();
  while (it != lEs.end()) {
    Entity* pE = *it;
    if (pE) {
      if (pE->isDestroyable() && pE) {
        delete pE;
        pE = NULL;
      }
    }
    ++it;
  }
  lEs.wipe();
}

void ListEntities::include(Entity* pE) { lEs.include(pE); }

void ListEntities::execute() {
  List<Entity>::Iterator it = lEs.begin();

  for (; it != lEs.end(); ++it) {
    Entity* entity = *it;
    entity->execute();
  }
}

void ListEntities::drawEntities() {
  // percorre a lista e faz as entidades executarem suas ações
  List<Entity>::Iterator it = lEs.begin();

  for (; it != lEs.end(); ++it) {
    Entity* entity = *it;
    entity->draw();
  }
}

}  // namespace Lists
}  // namespace DinoGame
