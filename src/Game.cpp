#include "Game.hpp"
#include "state_machine/Menu.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "managers/TimeManager.hpp"
#include "managers/CollisionManager.hpp"
#include "state_machine/State.hpp"

using namespace std;

Game::Game() : pGM(GraphicsManager::getInstance()), pCM(CollisionManager::getInstance()), currentState(NULL) {
  Ente::setGM(pGM);
  changeState(new Menu());

  //mPlayer = new Player();

  //mPlayer->setup();
  //mForestLevel.includePlayer(mPlayer);
  //mForestLevel.setup();

  std::srand(static_cast<unsigned int>(std::time(NULL)));
}

Game::~Game() {
    if (currentState)
    {
        delete currentState;
        currentState = NULL;
    }
    else
    {
        std::cout << "Game currentState is already NULL." << std::endl;
    }
}

// junta o processEvents, update e render em um loop infinito rodando o jogo
void Game::run() {
  TimeManager& timeManager = TimeManager::getInstance();

  while (pGM->isOpen()) {
    timeManager.updateClock();
    processEvents();
    update();
    render();
  }
}

void Game::changeState(State* newState)
{
    if (currentState)
    {
        delete currentState;
        currentState = NULL;
    }
    else
    {
        std::cout << "Game changeState currentState is already NULL." << std::endl;
    }
    currentState = newState;
    if (currentState)
    {
        currentState->setGameContext(this);
    }
    else
    {
        std::cout << "Game changeState failed to setGameContext." << std::endl;
    }
}

// checa inputs do usuario e fecha a janela quando o usuario clicar no X da
// janela
void Game::processEvents() {
  //sf::Event event;

  //while (pGM->pollEvent(event)) {
  //  if (event.type == sf::Event::Closed) {
  //    pGM->close();
  //  }

  //  else if (event.type == sf::Event::KeyPressed) {
  //    if (event.key.code == sf::Keyboard::Escape)
  //      pGM->close();  // temporario fechar pq ja basta ter q clicar n "X" toda
  //                   // vez :P
  //    mPlayer->handleInput(event.key.code, true);
  //  }

  //  else if (event.type == sf::Event::KeyReleased) {
  //    mPlayer->handleInput(event.key.code, false);
  //  }
  //}
    sf::Event event;
    while (pGM->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            pGM->close();
        }
        if (currentState)
        {
            // Nota: Você pode adaptar o processEvents do State para receber o sf::Event
            // Ou tratar o input de forma genérica dentro do estado.
            currentState->processEvents(event);
        }
    }
}

// atualiza a logica do jogo, como movimentacao de personagens, verificacao de
// colisoes, etc
void Game::update() { 
    //mForestLevel.execute(); 
    if (currentState)
    {
        currentState->updateTime();
        currentState->update();
    }
}

// atualiza a tela: apaga a tela anterior, desenha os novos objetos e mostra a
// nova tela para o usuario
void Game::render() {
  //pGM->clear();
  //pGM->updateCameraPos(mPlayer->getPosition());
  //mForestLevel.render();
  //// GM.showMousePosition();
  //pGM->drawPosition(mPlayer->getPosition());
  ////  mCurrentBone.draw(&GG.mWindow);
  //pGM->display();
    pGM->clear();
    if (currentState)
    {
        currentState->render();
    }
    pGM->display();
}
