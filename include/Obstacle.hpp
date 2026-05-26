#pragma once
<<<<<<< HEAD
#include "Entity.hpp"

class Obstacle : public Entity {
public:
	Obstacle();
	virtual ~Obstacle();
	//virtual void update(sf::Time deltaTime) = 0;
	//virtual void draw(sf::RenderWindow* window) = 0;
	//virtual sf::FloatRect getBounds() const = 0;
	virtual ObstacleType getObstacleType() const = 0;
	virtual EntityType getEntityType() const;
};
=======

#include "Entity.hpp"
#include "Player.hpp"
class Obstacle : public Entity {
 protected:
  bool harmful;

 public:
  Obstacle(const sf::Texture& texture) : Entity(texture) {}
  ~Obstacle() {}

  virtual void execute() = 0;
  virtual void save() = 0;
  virtual void obstruct(Player* pPlayer) = 0;
};
>>>>>>> 4795ee6bbd3d3fcd1a4b5ea5a06f8eca20a8fb09
