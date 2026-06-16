#include "entities/ListEntities.hpp"

ListEntities::ListEntities() : lEs() {}

ListEntities::~ListEntities() {
  List<Entity>::Iterator it = lEs.begin();
  while (it != lEs.end())

  {
      if (it.getCurrentElement() == nullptr) {
          break;
      }
    Entity* pE = *it;  // desreferencia (&(*it))
    if (pE) {
        uintptr_t* vptr = reinterpret_cast<uintptr_t*>(pE);
        if (vptr && *vptr != 0xDDDDDDDDDDDDDDDD && *vptr != 0x00000000) {
            if (pE->isDestroyable()) {
                delete pE;
                pE = NULL;
            }
            pE = NULL;
        }
    }
      it = lEs.erase(it); //o Wipe não vai fazer esse papel
    //++it;
  }
  //lEs.wipe();  // comentar aqui caso dê erro de ponteiro duplamente deletado
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
