#include "Game.hpp"

#include "SFML/Window/Keyboard.hpp"
#include "managers/TimeManager.hpp"

using namespace std;

Game::Game() : GM() {
  Ente::setGM(&GM);

  mPlayer.setTexture("PLAYER_TEXTURE");
  mForestLevel.includePlayer(&mPlayer);
  mForestLevel.setup();

  std::srand(static_cast<unsigned int>(std::time(NULL)));
}

Game::~Game() {}

// junta o processEvents, update e render em um loop infinito rodando o jogo
void Game::run() {
  TimeManager& timeManager = TimeManager::getInstance();

  while (GM.isOpen()) {
    timeManager.updateClock();
    processEvents();
    execute();
    render();
  }
}

// checa inputs do usuario e fecha a janela quando o usuario clicar no X da
// janela
void Game::processEvents() {
  sf::Event event;

  while (GM.mWindow.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      GM.close();
    }

    else if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Escape)
        GM.close();  // temporario fechar pq ja basta ter q clicar n "X" toda
                     // vez :P
      mPlayer.handleInput(event.key.code, true);
    }

    else if (event.type == sf::Event::KeyReleased) {
      mPlayer.handleInput(event.key.code, false);
    }
  }
}

// atualiza a logica do jogo, como movimentacao de personagens, verificacao de
// colisoes, etc
void Game::execute() { mForestLevel.execute(); }

// atualiza a tela: apaga a tela anterior, desenha os novos objetos e mostra a
// nova tela para o usuario
void Game::render() {
  GM.clear();
  GM.updateCameraPos(mPlayer.getPosition());
  mForestLevel.render();
  // GM.showMousePosition();
  GM.drawPosition(mPlayer.getPosition());
  //  mCurrentBone.draw(&GG.mWindow);
  GM.display();
}
