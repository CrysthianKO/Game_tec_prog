#include "ListEntities.hpp"

ListEntities::ListEntities() {}

ListEntities::~ListEntities() {}

void ListEntities::include(Entity* pE) { lEs.include(pE); }

void ListEntities::iterate() {
  List<Entity>::Iterator it = lEs.begin();

  for (; it != lEs.end(); ++it) {
    Entity* entity = *it;
    entity->draw();
  }
  // percorre a lista e faz as entidades executarem suas ações
}
