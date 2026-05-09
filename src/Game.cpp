#include "Game.hpp"

// (hard coded)
Game::Game(): 
    mWindow(sf::VideoMode({ width, height }), "JOGO MYTO BOM"),
    width(1366),
    height(768),
    mPlayer(mPlayerTexture),
    mScore(0),
    timePerFrame(sf::seconds(1.f / 60.f)) // 60 fps (hard coded)
    //mScoreText()
{
    //carrega a fonte do disco rigido
    if (mFont.openFromFile("c:/Windows/Fonts/Arial.ttf"))
    {
        // Agora você inicializa o objeto text dentro do optional
        mScoreText.emplace(mFont, "Score: 0", 24); 
        mScoreText->setFillColor(sf::Color::White);
        mScoreText->setPosition({10.f, 10.f});
    }
    
    //std::ifstream file("C:/Windows/Fonts/Arial.ttf", std::ios::binary);
    //if (file) {
    //    std::vector<char> data((std::istreambuf_iterator<char>(file)),
    //        std::istreambuf_iterator<char>());
    //    if (!data.empty() && mFont.loadFromMemory(data.data(), data.size())) {
    //        mScoreText.setFont(mFont);
    //        mScoreText.setCharacterSize(24);
    //        mScoreText.setFillColor(sf::Color::White);
    //        mScoreText.setString("Score: 0");
    //        mScoreText.setPosition(10.f, 10.f);
    //    }
    //}
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

  while (mWindow.isOpen()) {
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
  while (const std::optional event = mWindow.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      mWindow.close();
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
  mWindow.clear();
  // Verifica se mScoreText foi inicializado com sucesso
  if (mScoreText.has_value()) {
      mWindow.draw(*mScoreText); // Usa o * para acessar o objeto sf::Text
  }
  mPlayer.draw(mWindow);
  mCurrentBone.draw(&mWindow);
  mWindow.display();
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
