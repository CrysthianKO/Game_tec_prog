#include "entities/obstacles/Obstacle.hpp"

class Fire : public Obstacle {
 private:
  float static position;

 public:
  Fire();
  ~Fire();

  void execute();
  void save();
  void obstruct(Player* pPlayer, sf::FloatRect intercession);
  ObstacleType getObstacleType() const;
};
