#include "levels/ExtinctionLevel.hpp"

#include "entities/characters/DinoBoss.hpp"
#include "entities/obstacles/Fire.hpp"
#include "entities/projectile/LaserBall.hpp"
#include "managers/CollisionManager.hpp"

ExtinctionLevel::ExtinctionLevel() {
  maxBoss = 4;
  maxHardObstacles = 6;
}

ExtinctionLevel::~ExtinctionLevel() {}

void ExtinctionLevel::setup() {
  pCM->includeLevel(this);
  createScenario();
  createEasyEnemies();
  createEnemies();
  createPlatforms();
  createObstacles();
}

void ExtinctionLevel::render() {
  drawBackground();
  pListEntities->drawEntities();
  drawGround();
}

void ExtinctionLevel::execute() {
  pCM->execute();
  pListEntities->execute();
}

void ExtinctionLevel::createEnemies() {
  int max = rand() % (maxBoss - 3 + 1) + 3;
  for (int i = 0; i < max; i++) {
    DinoBoss* boss = new DinoBoss();
    LaserBall* laser = new LaserBall();
    boss->setLaserBall(laser);
    pListEntities->include(boss);
    pCM->includeEnemy(boss);
    pListEntities->include(laser);
    pCM->includeProjectile(laser);
  }
}
void ExtinctionLevel::createObstacles() {
  int max = rand() % (maxHardObstacles - 3 + 1) + 3;
  for (int i = 0; i < max; i++) {
    Fire* fire = new Fire();
    pListEntities->include(fire);
    pCM->IncludeObstacle(fire);
  }
}
void ExtinctionLevel::createScenario() {
  for (int i = 0; i <= 5; i++) {
    string id = "EXTINCTION_BACKGROUND_" + to_string(i);
    addBackgroundLayer(id, 0.0f);
  }
  for (int i = 0; i <= 1; i++) {
    string id = "EXTINCTION_GROUND_" + to_string(i);
    addGroundLayer(id);
  }

  sf::Vector2f oldPos = mGround[0].getPosition();
  mGround[0].setPosition(oldPos.x, -20);
  mGround[1].setPosition(oldPos.x, -20);
  mGroundLevel = mGround[0].getLocalBounds().height - 75.f;
}
