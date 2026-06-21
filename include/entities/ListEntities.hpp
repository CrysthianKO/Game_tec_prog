#pragma once
#include "List.hpp"

namespace DinoGame {
namespace Entities {
class Entity;
}
namespace Lists {

class ListEntities {
 private:
  List<Entities::Entity> lEs;

 public:
  ListEntities();
  ~ListEntities();

  ListEntities(const ListEntities& other) = delete;
  ListEntities& operator=(const ListEntities& other) = delete;

  void include(Entities::Entity* pE);
  void execute();
  void drawEntities();
};

}  // namespace Lists
}  // namespace DinoGame
