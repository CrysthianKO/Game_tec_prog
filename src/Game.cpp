#include "Game.hpp"

#include "entities/characters/Player.hpp"
#include "managers/CollisionManager.hpp"
#include "managers/TimeManager.hpp"
#include "state_machine/ExtinctionLevelState.hpp"
#include "state_machine/ForestLevelState.hpp"
#include "state_machine/Menu.hpp"
#include "state_machine/Ranking.hpp"
#include "state_machine/State.hpp"

using namespace std;

Game::Game()
    : pGM(GraphicsManager::getInstance()),
      pCM(CollisionManager::getInstance()),
      pTM(TimeManager::getInstance()),
      pPlayer1(NULL),
      pPlayer2(NULL),
      currentState(NULL),
      nextState(NULL) {
  Ente::setGM(pGM);
  Ente::setTM(pTM);
  pPlayer1 = new Player(1);
  pPlayer2 = new Player(2);
  pPlayer1->setup();
  pPlayer2->setup();

  changeState(new Menu());

  std::srand(static_cast<unsigned int>(std::time(NULL)));
}

Game::~Game() {
  if (currentState) {
    delete currentState;
    currentState = NULL;
  } else {
    std::cout << "Game currentState is already NULL." << std::endl;
  }
  if (pGM) {
    delete pGM;
    pGM = NULL;
  }
  if (pCM) {
    delete pCM;
    pCM = NULL;
  }
  if (pTM) {
    delete pTM;
    pTM = NULL;
  }
  if (pPlayer1) {
    delete pPlayer1;
    pPlayer1 = NULL;
  }
  if (pPlayer2) {
    delete pPlayer2;
    pPlayer2 = NULL;
  }
}

// junta o processEvents, update e render em um loop infinito rodando o jogo
void Game::run() {
  while (pGM->isOpen()) {
    applyChangeState();
    pTM->updateClock();
    processEvents();
    update();
    render();
  }
}

void Game::applyChangeState(/*State* newState*/) {
  if (nextState) {
    if (currentState) {
      if (currentState->getID() == StateID::Menu) {
        delete static_cast<Menu*>(currentState);
        currentState = NULL;
      } else if (currentState->getID() == StateID::Ranking) {
        delete static_cast<Ranking*>(currentState);
        currentState = NULL;
      } else if (currentState->getID() == StateID::ForestLevel) {
        delete static_cast<ForestLevelState*>(currentState);
        currentState = NULL;
      } else if (currentState->getID() == StateID::ExtinctionLevel) {
        delete static_cast<ExtinctionLevelState*>(currentState);
        currentState = NULL;
      } else {
        delete currentState;
        currentState = NULL;
      }
    } else {
      std::cout << "Game changeState currentState is already NULL."
                << std::endl;
    }
    currentState = nextState;
    nextState = NULL;
    if (currentState) {
      currentState->setGameContext(this);
    } else {
      std::cout << "Game changeState failed to setGameContext." << std::endl;
    }
  }
}

void Game::changeState(State* newState) {
  if (nextState) {
    delete nextState;
    nextState = NULL;
  }
  nextState = newState;
}

// checa inputs do usuario e fecha a janela quando o usuario clicar no X da
// janela
void Game::processEvents() {
  // sf::Event event;

  // while (pGM->pollEvent(event)) {
  //   if (event.type == sf::Event::Closed) {
  //     pGM->close();
  //   }

  //  else if (event.type == sf::Event::KeyPressed) {
  //    if (event.key.code == sf::Keyboard::Escape)
  //      pGM->close();  // temporario fechar pq ja basta ter q clicar n "X"
  //      toda
  //                   // vez :P
  //    mPlayer->handleInput(event.key.code, true);
  //  }

  //  else if (event.type == sf::Event::KeyReleased) {
  //    mPlayer->handleInput(event.key.code, false);
  //  }
  //}
  sf::Event event;
  while (pGM->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      pGM->close();
    }
    if (currentState) {
      // Nota: Você pode adaptar o processEvents do State para receber o
      // sf::Event Ou tratar o input de forma genérica dentro do estado.
      currentState->processEvents(event);
    }
  }
}

// atualiza a logica do jogo, como movimentacao de personagens, verificacao de
// colisoes, etc
void Game::update() {
  if (currentState) {
    currentState->updateTime();
    currentState->update();
  }
}

// atualiza a tela: apaga a tela anterior, desenha os novos objetos e mostra a
// nova tela para o usuario
void Game::render() {
  pGM->clear();
  if (currentState) {
    currentState->render();
  }
  pGM->display();
}

Player* Game::getPlayer1() { return pPlayer1; }
Player* Game::getPlayer2() { return pPlayer2; }
