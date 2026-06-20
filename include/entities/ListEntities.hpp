#pragma once
#include "List.hpp"

namespace DinoGame {
namespace Lists {

class Entity;

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

}  // namespace Lists
}  // namespace DinoGame
