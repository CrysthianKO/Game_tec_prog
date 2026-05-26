#pragma once
<<<<<<< HEAD
#include "Obstacle.hpp"

class Platform : public Obstacle {
public:
	Platform();
	virtual ~Platform();
	//virtual void update(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	//virtual sf::FloatRect getBounds() const;
	virtual ObstacleType getObstacleType() const;
};
=======

#include "Obstacle.hpp"
class Platform : public Obstacle {
 private:
  float height;

 public:
  Platform(const sf::Texture& texture);
  ~Platform();

  void execute();
  void save();
  void obstruct(Player* pPlayer);
  sf::FloatRect getBounds() const;
};
>>>>>>> 4795ee6bbd3d3fcd1a4b5ea5a06f8eca20a8fb09
