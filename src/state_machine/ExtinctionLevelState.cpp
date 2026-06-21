#include "state_machine/ExtinctionLevelState.hpp"

#include "Game.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "entities/characters/Player.hpp"
#include "levels/ExtinctionLevel.hpp"
#include "managers/CollisionManager.hpp"
#include "state_machine/Menu.hpp"
#include "state_machine/Ranking.hpp"

namespace DinoGame {
namespace StateMachine {

using namespace Managers;
using namespace Entities::Characters;

ExtinctionLevelState::ExtinctionLevelState()
    : State(),
      extinctionLevel(),
      pPlayer1(NULL),
      pPlayer2(NULL),
      pGM(GraphicsManager::getInstance()),
      pCM(CollisionManager::getInstance()) {
  id = StateID::ExtinctionLevel;
}

ExtinctionLevelState::~ExtinctionLevelState() { pCM->clearComponents(); }

void ExtinctionLevelState::setGameContext(Game* game) {
  State::setGameContext(game);
  if (pGame) {
    pPlayer1 = pGame->getPlayer1();
    pPlayer2 = pGame->getPlayer2();
    pPlayer1->setup();
    pPlayer2->setup();
    pPlayer1->setPosition(sf::Vector2f(20.f, 510.f));
    pPlayer2->setPosition(sf::Vector2f(50.f, 510.f));
    extinctionLevel.setup();
    extinctionLevel.includePlayer(pPlayer1);
    extinctionLevel.includePlayer(pPlayer2);
  }
}

void ExtinctionLevelState::processEvents(const sf::Event& event) {
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
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    pGame->changeState(new Menu());
    pPlayer1->setScore(0);
    pPlayer2->setScore(0);
  }
}

void ExtinctionLevelState::update() {
  extinctionLevel.execute();
  winLevel();
  if (pPlayer1->getNumberLives() <= 0 && pPlayer2->getNumberLives() <= 0)
    pGame->changeState(new Ranking());
}

void ExtinctionLevelState::winLevel() {
  if (pPlayer1) {
    if (pPlayer1->getPosition().x > extinctionLevel.getWall()) {
      pGame->changeState(new Ranking());
      return;
    }
  }
  if (pPlayer2) {
    if (pPlayer2->getPosition().x > extinctionLevel.getWall()) {
      pGame->changeState(new Ranking());
      return;
    }
  }
}

void ExtinctionLevelState::render() {
  if (pPlayer1->getNumberLives() > 0) {
    pGM->updateCameraPos(pPlayer1->getPosition());
  } else {
    pGM->updateCameraPos(pPlayer2->getPosition());
  }
  extinctionLevel.render();
  extinctionLevel.drawHUD(pPlayer1, pPlayer2);
}

}  // namespace StateMachine
}  // namespace DinoGame
