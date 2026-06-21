#include "SFML/Graphics/Color.hpp"
#include "entities/characters/Enemy.hpp"

namespace DinoGame {
namespace Entities {
class LaserBall;
namespace Characters {

class DinoBoss : public Enemy {
 private:
  static float position;
  float mTimerShoot;
  LaserBall* pLaser;
  sf::Color mColor;

 public:
  DinoBoss();
  virtual ~DinoBoss();
  void save();
  void execute();
  void move();
  void damage();
  void setLaserBall(LaserBall* pL);
  LaserBall* getLaserBall();
};
}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
