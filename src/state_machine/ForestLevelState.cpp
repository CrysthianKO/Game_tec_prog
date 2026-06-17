#include "state_machine/ForestLevelState.hpp"

#include "Game.hpp"
#include "managers/CollisionManager.hpp"
#include "state_machine/ExtinctionLevelState.hpp"
#include "state_machine/Menu.hpp"
// #include "entities/characters/Player.hpp"
// #include "levels/ForestLevel.hpp"

ForestLevelState::ForestLevelState()
    : State(),
      forestLevel(),
      pPlayer1(NULL),
      pPlayer2(NULL),
      pGM(GraphicsManager::getInstance()),
      pCM(CollisionManager::getInstance()) {}

ForestLevelState::~ForestLevelState() { pCM->clearComponents(); }

void ForestLevelState::setGameContext(Game* game) {
  State::setGameContext(game);
  if (pGame) {
    forestLevel.setup();
    pPlayer1 = pGame->getPlayer1();
    pPlayer2 = pGame->getPlayer2();
    pPlayer1->setPosition(sf::Vector2f(20.f, 510.f));
    pPlayer2->setPosition(sf::Vector2f(50.f, 510.f));
    forestLevel.includePlayer(pPlayer1);
    forestLevel.includePlayer(pPlayer2);
  }
}

void ForestLevelState::processEvents(const sf::Event& event) {
  switch (event.type) {
    // input do usuário true
    case sf::Event::KeyPressed:
      if (pPlayer2) pPlayer2->handleInput(event.key.code, true);
      if (pPlayer1) pPlayer1->handleInput(event.key.code, true);

      break;
    case sf::Event::KeyReleased:
      // input do usuário false
      if (pPlayer2) pPlayer2->handleInput(event.key.code, false);
      if (pPlayer1) pPlayer1->handleInput(event.key.code, false);
      break;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    pGame->changeState(new Menu());
}

void ForestLevelState::update() {
  forestLevel.execute();
  winLevel();
}

void ForestLevelState::winLevel() {
  if (pPlayer1) {
    if (pPlayer1->getPosition().x > forestLevel.getWall()) {
      pGame->changeState(new ExtinctionLevelState());
    }
  }
  if (pPlayer2) {
    if (pPlayer2->getPosition().x > forestLevel.getWall()) {
      pGame->changeState(new ExtinctionLevelState());
    }
  }
}

void ForestLevelState::render() {
  pGM->updateCameraPos(pPlayer1->getPosition());
  forestLevel.render();
  pGM->drawPosition(pPlayer1->getPosition());
}
