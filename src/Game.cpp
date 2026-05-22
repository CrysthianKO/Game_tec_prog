#include "Game.hpp"

// (hard coded)
Game::Game(): 
    //mWindow(sf::VideoMode({ width, height }), "JOGO MYTO BOM"),
    //width(1366),
    //height(768),
    mGraphicsManager(),
    mPlayer(),
    mCurrentBone(),
    mScore(0),
    timePerFrame(sf::seconds(1.f / 60.f)) // 60 fps (hard coded)
    //mScoreText()
{
	// Define o GraphicsManager para os Entes
	Ente::setGraphicsManager(&mGraphicsManager);

    //carrega a fonte do disco rigido
    if (mFont.openFromFile("c:/Windows/Fonts/Arial.ttf"))
    {
        // Agora você inicializa o objeto text dentro do optional
        mScoreText.emplace(mFont, "Score: 0", 24); 
        mScoreText->setFillColor(sf::Color::White);
        mScoreText->setPosition({10.f, 10.f});
    }
    
    std::srand(static_cast<unsigned int>(std::time(NULL)));
}

Game::~Game()
{

}

//junta o processEvents, update e render em um loop infinito rodando o jogo
void Game::run()
{
  sf::Clock clock;
  //implementa dt
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  //enquanto a janela do graphics manager estiver aberta, o jogo continua rodando. Dentro do loop, processa os eventos do usuario, atualiza a logica do jogo e renderiza a tela
  while (mGraphicsManager.mWindow.isOpen()) {
    processEvents();
    timeSinceLastUpdate += clock.restart();
    //garante que o jogo seja atualizado a uma taxa constante, mesmo que o tempo de processamento de cada frame varie
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      processEvents();
      update(timePerFrame);
    }
    render();
  }
}

//checa inputs do usuario e fecha a janela quando o usuario clicar no X da janela
void Game::processEvents() {
  while (const std::optional event = mGraphicsManager.mWindow.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      mGraphicsManager.mWindow.close();
    }

    else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
      mPlayer.handleInput(keyPressed->code, true);
    }

    else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
      mPlayer.handleInput(keyReleased->code, false);
    }
  }
}

//atualiza a logica do jogo, como movimentacao de personagens, verificacao de colisoes, etc
void Game::update(sf::Time dt) 
{ 
    mPlayer.update(dt);
    mCurrentBone.updateAnimation(dt);
    //verifica se o jogador colidiu com o osso
    if (mPlayer.getBounds().findIntersection(mCurrentBone.getBounds()))
    {
        mCurrentBone.respawn();
        addScore(&mCurrentBone);

		//som de coleta aqui (opcional)
    }
}


//atualiza a tela: apaga a tela anterior, desenha os novos objetos e mostra a nova tela para o usuario
void Game::render() {
  mGraphicsManager.mWindow.clear();
  // Verifica se mScoreText foi inicializado com sucesso
  if (mScoreText.has_value()) {
      mGraphicsManager.mWindow.draw(*mScoreText); // Usa o * para acessar o objeto sf::Text
  }

  //chamada polimórfica do desenho, cada Ente sabe como se desenhar usando o pGM interno
  mPlayer.draw();
  mCurrentBone.draw();

  mGraphicsManager.mWindow.display();
}

//adiciona a pontuação do osso ao score total e atualiza o texto de pontuação na tela
void Game::addScore(Bone* bone)
{
    if (bone == NULL)
        return;
    mScore += bone->getScoreValue();
    // Se mScoreText existir, atualiza a string
    if (mScoreText) {
        mScoreText->setString("Score: " + std::to_string(mScore));
    }
}
