#include "Entity.hpp"
#include "List.hpp"
class ListEntities {
 private:
  List<Entity> lEs;

 public:
  ListEntities();
  ~ListEntities();
  void include(Entity* pE);
  void iterate();
};
