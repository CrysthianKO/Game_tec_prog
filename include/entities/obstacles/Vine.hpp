#include "entities/obstacles/Obstacle.hpp"
class Vine : public Obstacle {
 private:
  static float position;

 public:
  Vine();
  ~Vine();

  void execute();
  void save();
  void obstruct(Player* pPlayer, sf::FloatRect intercession);
};
