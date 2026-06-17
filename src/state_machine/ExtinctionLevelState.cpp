#include "state_machine/ExtinctionLevelState.hpp"

#include "Game.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "entities/characters/Player.hpp"
#include "levels/ExtinctionLevel.hpp"
#include "managers/CollisionManager.hpp"
#include "state_machine/Menu.hpp"

ExtinctionLevelState::ExtinctionLevelState()
    : State(),
      extinctionLevel(),
      pPlayer1(NULL),
      pPlayer2(NULL),
      pGM(GraphicsManager::getInstance()),
      pCM(CollisionManager::getInstance()) {}

ExtinctionLevelState::~ExtinctionLevelState() { pCM->clearComponents(); }

void ExtinctionLevelState::setGameContext(Game* game) {
  State::setGameContext(game);
  if (pGame) {
    extinctionLevel.setup();
    pPlayer1 = pGame->getPlayer1();
    pPlayer2 = pGame->getPlayer2();
    pPlayer1->setPosition(sf::Vector2f(20.f, 510.f));
    pPlayer2->setPosition(sf::Vector2f(50.f, 510.f));
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
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    pGame->changeState(new Menu());
}

void ExtinctionLevelState::update() { extinctionLevel.execute(); }

void ExtinctionLevelState::render() {
  pGM->updateCameraPos(pPlayer1->getPosition());
  extinctionLevel.render();
  pGM->drawPosition(pPlayer1->getPosition());
}
