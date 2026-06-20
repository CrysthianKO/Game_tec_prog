#pragma once
#include <SFML/Graphics.hpp>

#include "managers/TimeManager.hpp"

namespace DinoGame {
namespace Managers {

class Physics {
 private:
  TimeManager* pTM;
  const float gravity;
  const float springStiffness;
  const float dampingFactor;
  static Physics* instance;

 private:
  Physics();

 public:
  ~Physics();
  static Physics* getInstance();

  void applyGravity(sf::Vector2f& velocity);
  void applyLevitation(sf::Vector2f& velocity);
  void applyDampedOscillator(sf::Vector2f& velocity,
                             const sf::Vector2f& currentPos,
                             const sf::Vector2f targetPos);
};

}  // namespace Managers
}  // namespace DinoGame
