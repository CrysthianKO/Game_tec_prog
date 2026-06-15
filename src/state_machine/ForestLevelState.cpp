#include "state_machine/ForestLevelState.hpp"

#include "Game.hpp"
#include "managers/CollisionManager.hpp"
#include "state_machine/Menu.hpp"
// #include "entities/characters/Player.hpp"
// #include "levels/ForestLevel.hpp"

ForestLevelState::ForestLevelState()
    : State(),
      player1(NULL),
      level1(),
      pGM(GraphicsManager::getInstance()),
      pCM(CollisionManager::getInstance()) {
  player1 = new Player();
  player1->setup();
  level1.includePlayer(player1);
  level1.setup();
  // colisões específicas da fase 1 aqui
  // pCM->includePlayer(player1);
}

ForestLevelState::~ForestLevelState() {
  pCM->clearComponents();

  if (player1) {
    delete player1;
    player1 = NULL;
  }
}

void ForestLevelState::processEvents(const sf::Event& event) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    player1->handleInput(sf::Keyboard::Left, true);
  // sf::Event event;
  switch (event.type) {
    case sf::Event::KeyPressed:
      // input do usuário true
      player1->handleInput(event.key.code, true);
      break;
    case sf::Event::KeyReleased:
      // input do usuário false
      player1->handleInput(event.key.code, false);
      break;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    pGame->changeState(new Menu());
}

void ForestLevelState::update() {
  // player1->execute();
  level1.execute();
  // pCM->execute();
}

void ForestLevelState::render() {
  pGM->updateCameraPos(player1->getPosition());
  level1.render();
  pGM->drawPosition(player1->getPosition());
}
