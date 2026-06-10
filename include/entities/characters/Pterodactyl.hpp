#include "entities/characters/Enemy.hpp"

class Pterodactyl : public Enemy {
 private:
  static float position;

 public:
  Pterodactyl();
  ~Pterodactyl();
  void execute();
  void save();
  void damage();
  EnemyType getEnemyType() const;
};
