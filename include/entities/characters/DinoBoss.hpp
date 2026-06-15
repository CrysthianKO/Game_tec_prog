#include "entities/characters/Enemy.hpp"
#include "entities/projectile/LaserBall.hpp"

class DinoBoss : public Enemy {
 private:
  int mStrength;
  static float position;
  float mTime;
  float mTimerShoot;
  LaserBall* pLaser;

 public:
  DinoBoss();
  virtual ~DinoBoss();
  void save();
  void execute();
  void move();
  void damage();
  void setLaserBall(LaserBall* pL);
  EnemyType getEnemyType() const;
  // LaserBall* getLaserBall();
};
