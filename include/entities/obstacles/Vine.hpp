#include "entities/obstacles/Obstacle.hpp"
class Vine : public Obstacle {
 public:
  Vine(float xPos);
  ~Vine();

  void execute();
  void save();
  void obstruct(Player* pPlayer, sf::FloatRect intercession);
};
