#include "entities/characters/Enemy.hpp"

class Pterodactyl : public Enemy {
 public:
  Pterodactyl();
  ~Pterodactyl();
  void execute();
  void save();
  void damage();
  EnemyType getEnemyType() const;
};
