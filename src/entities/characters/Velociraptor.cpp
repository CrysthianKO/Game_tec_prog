#include "entities/characters/Velociraptor.hpp"

#include <cmath>

#include "SFML/System/Vector2.hpp"
#include "managers/TimeManager.hpp"

Velociraptor::Velociraptor() { setup(); }

Velociraptor::~Velociraptor() {}

void Velociraptor::setup() {
  mSpeed = 4.2f;
  mVelocity.y = 600.f;
  mWalkingTime = 0;
  mMovingRight = true;
  mRange = 160.f;
  mSprite.scale(sf::Vector2f(1.8, 1.8));
  float xPos =
      rand() % (320 - 1100 + 1) + 320;  // (inicial - final + 1) + inicial
  mSpawnX = xPos;
  mSprite.setPosition(xPos, 500);
  mSprite.setTextureRect(sf::IntRect({0, 0}, {51, 26}));
}

void Velociraptor::save() {}
void Velociraptor::execute() {
  float dt = TimeManager::getInstance().getDeltaTime();
  mWalkingTime += dt;
  if (mWalkingTime > 0.5f) {
    mMovingRight = rand() % 2;
    mWalkingTime = 0.f;
  }

  float leftWall = mSpawnX - mRange;
  float rightWall = mSpawnX + mRange;

  if (mSprite.getPosition().x > rightWall) {
    mMovingRight = false;
    mWalkingTime = 0.f;
  }
  if (mSprite.getPosition().x < leftWall) {
    mMovingRight = true;
    mWalkingTime = 0.f;
  }

  sf::Vector2f moviment = {0.f, 0.f};

  if (mMovingRight)
    moviment.x += mSpeed;
  else
    moviment.x -= mSpeed;

  moviment.y = mVelocity.y * dt;

  mSprite.move(moviment);

  if (mOnGround) mVelocity.y = 0.f;
}

void Velociraptor::damage() { mSprite.move(sf::Vector2f(10000, 1000)); }

// sf::FloatRect Velociraptor::getBounds() const {
//	//temporiariamente retorna um retângulo vazio, já que o cogumelo ainda
// não tem uma sprite ou forma definida 	return sf::FloatRect();
// }

EnemyType Velociraptor::getEnemyType() const {
  return EnemyType::EN_VELOCIRAPTOR;
}
