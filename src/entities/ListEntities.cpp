#include "entities/ListEntities.hpp"

ListEntities::ListEntities() {}

ListEntities::~ListEntities() {}

void ListEntities::include(Entity* pE) { lEs.include(pE); }

void ListEntities::execute() {}

void ListEntities::drawEntities() {
  // percorre a lista e faz as entidades executarem suas ações
  List<Entity>::Iterator it = lEs.begin();

  for (; it != lEs.end(); ++it) {
    Entity* entity = *it;
    entity->draw();
  }
}
