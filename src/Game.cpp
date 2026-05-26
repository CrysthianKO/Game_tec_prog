#include "Game.hpp"

#include <stdexcept>

using namespace std;

Game::Game()
    : GM(),
      mPlayer(mPlayerTexture),
      mPlat(mPlatformTex),
      timePerFrame(sf::seconds(1.f / 60.f))  // 60 fps (hard coded)
{
  Ente::setGM(&GM);

  if (!mPlayerTexture.loadFromFile(
          "media/Massospondylus_idle_spritesheet.png")) {
    throw std::invalid_argument("ERROR: COUL NOT LOAD FILE");
  }
  if (!mPlatformTex.loadFromFile("media/platform-test.png")) {
    throw std::invalid_argument("ERROR: COUL NOT LOAD FILE");
  }
  listEntities.include(static_cast<Entity*>(&mPlayer));
  listEntities.include(static_cast<Entity*>(&mPlat));

  std::srand(static_cast<unsigned int>(std::time(NULL)));
}

Game::~Game() {}

// junta o processEvents, update e render em um loop infinito rodando o jogo
void Game::execute() {
  sf::Clock clock;
  // implementa dt
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (GM.isOpen()) {
    processEvents();
    timeSinceLastUpdate += clock.restart();
    // garante que o jogo seja atualizado a uma taxa constante, mesmo que o
    // tempo de processamento de cada frame varie
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      // processEvents();
      update(timePerFrame);
    }
    render();
  }
}

// checa inputs do usuario e fecha a janela quando o usuario clicar no X da
// janela
void Game::processEvents() {
  while (const std::optional event = GM.mWindow.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      GM.close();
    }

    else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
      mPlayer.handleInput(keyPressed->code, true);
    }

    else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
      mPlayer.handleInput(keyReleased->code, false);
    }
  }
}

// atualiza a logica do jogo, como movimentacao de personagens, verificacao de
// colisoes, etc
void Game::update(sf::Time dt) {
  // verifica se o jogador colidiu com o osso
}

// atualiza a tela: apaga a tela anterior, desenha os novos objetos e mostra a
// nova tela para o usuario
void Game::render() {
  GM.clear();
  listEntities.iterate();
  GM.drawPosition(mPlayer.getPosition());
  // mCurrentBone.draw(&GG.mWindow);
  GM.display();
}
