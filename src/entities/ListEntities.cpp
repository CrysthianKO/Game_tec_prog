#include "entities/ListEntities.hpp"

ListEntities::ListEntities() : lEs() {}

ListEntities::~ListEntities() {
	List<Entity>::Iterator it = lEs.begin();
	while (it != lEs.end())
	{
		Entity* pE = *it; //desreferencia (&(*it))
		if (pE)
		{
			if (pE->isDestroyable()) {
				delete pE;
			}
			pE = NULL;
		}
		it = lEs.erase(it);
		//++it;
	}
	//lEs.wipe(); //comentar aqui caso dê erro de ponteiro duplamente deletado
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
