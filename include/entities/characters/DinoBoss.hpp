#include "entities/characters/Enemy.hpp"

class DinoBoss : public Enemy {
 private:
  int mStrength;
  static float position;

 public:
  DinoBoss();
  virtual ~DinoBoss();
  void save();
  void execute();
  void move();
  void damage();
  EnemyType getEnemyType() const;
  // LaserBall* getLaserBall();
};
