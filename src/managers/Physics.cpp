#include "managers/Physics.hpp"

#include "SFML/System/Vector2.hpp"
#include "managers/TimeManager.hpp"

namespace DinoGame {
namespace Managers {

Physics* Physics::instance = NULL;

Physics::Physics()
    : pTM(TimeManager::getInstance()),
      gravity(1950.0f),
      springStiffness(15.f),
      dampingFactor(2.f) {}
Physics::~Physics() {}

Physics* Physics::getInstance() {
  if (!instance) {
    instance = new Physics();
  }
  return instance;
}

void Physics::applyGravity(sf::Vector2f& velocity) {
  float dt = pTM->getDeltaTime();
  velocity.y += gravity * dt;
}

void Physics::applyLevitation(sf::Vector2f& velocity) {
  float dt = pTM->getDeltaTime();
  velocity.y -= gravity * dt;
}

void Physics::applyDampedOscillator(sf::Vector2f& velocity,
                                    const sf::Vector2f& currentPos,
                                    const sf::Vector2f targetPos) {
  float dt = pTM->getDeltaTime();
  if (dt <= 0.f) return;
  // float damping = std::exp(-dampingFactor * dt);
  // float omega = std::sqrt((springStiffness * springStiffness) - dampingFactor
  // * dampingFactor); velocity.y = velocity.y * damping * std::cos(omega * dt);
  //  Calcula a distância atual até o ponto original de repouso
  sf::Vector2f displacement = currentPos - targetPos;

  // Lei de Hooke + Amortecimento: a = -k*x - c*v
  sf::Vector2f acceleration;
  acceleration.x = (-springStiffness * springStiffness * displacement.x) -
                   (2.0f * dampingFactor * velocity.x);
  acceleration.y = (-springStiffness * springStiffness * displacement.y) -
                   (2.0f * dampingFactor * velocity.y);

  // Atualiza apenas a velocidade
  velocity += acceleration * dt;
}

}  // namespace Managers
}  // namespace DinoGame
