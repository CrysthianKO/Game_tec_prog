#include "Entity.hpp"
#include "List.hpp"
class ListEntities {
 private:
  List<Entity> lEs;

 public:
  ListEntities();
  ~ListEntities();

  ListEntities(const ListEntities& other) = delete;
  ListEntities& operator=(const ListEntities& other) = delete;

  void include(Entity* pE);
  void execute();
  void drawEntities();
};
