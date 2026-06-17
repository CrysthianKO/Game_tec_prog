#include "state_machine/Menu.hpp"

#include "Game.hpp"
#include "state_machine/ExtinctionLevelState.hpp"
#include "state_machine/ForestLevelState.hpp"
#include "state_machine/Ranking.hpp"

Menu::Menu() : Ente(), State(), selectedOption(1) {
  // std::cout << "Menu Inicializado. Use as teclas 1 ou 2 para selecionar a
  // fase." << std::endl;
  if (!font.loadFromFile("media/fonte_teste.ttf")) {
    std::cout << "Erro ao carregar a fonte no menu" << std::endl;
  }
  float posX = pGM->getWindowWidth() - 100.f;
  float posY = pGM->getWindowHeight();

  // Configuração Titulo
  txtTitle.setFont(font);
  txtTitle.setString("Massospondylus The Revenge");
  txtTitle.setCharacterSize(40);
  txtTitle.setFillColor(sf::Color::White);
  txtTitle.setPosition(sf::Vector2f(posX / 2 - 150.f, posY / 2 - 300.f));

  // Configuração do Botão 1 (Fase Floresta)
  btnLevel1.setSize(sf::Vector2f(200.f, 50.f));
  btnLevel1.setFillColor(sf::Color::Green);
  btnLevel1.setPosition(sf::Vector2f(posX / 2, posY / 2 - 100.f));

  txtLevel1.setFont(font);
  txtLevel1.setString("Fase Floresta");
  txtLevel1.setCharacterSize(20);
  txtLevel1.setFillColor(sf::Color::White);
  // Centraliza o texto no botão
  txtLevel1.setPosition(btnLevel1.getPosition().x + 25.f,
                        btnLevel1.getPosition().y + 12.f);

  // Configuração do Botão 2 (Fase Extincao)
  btnLevel2.setSize(sf::Vector2f(200.f, 50.f));
  btnLevel2.setFillColor(sf::Color::Red);
  btnLevel2.setPosition(
      sf::Vector2f(posX / 2, btnLevel1.getPosition().y + 100.f));

  txtLevel2.setFont(font);
  txtLevel2.setString("Fase Extincao");
  txtLevel2.setCharacterSize(20);
  txtLevel2.setFillColor(sf::Color::White);
  txtLevel2.setPosition(btnLevel2.getPosition().x + 25.f,
                        btnLevel2.getPosition().y + 12.f);

  // Configuração do Botão Ranking (Leaderboard)
  btnRanking.setSize(sf::Vector2f(200.f, 50.f));
  btnRanking.setFillColor(sf::Color::Blue);
  btnRanking.setPosition(
      sf::Vector2f(posX / 2, btnLevel1.getPosition().y + 200.f));

  txtRanking.setFont(font);
  txtRanking.setString("Leaderboard");
  txtRanking.setCharacterSize(20);
  txtRanking.setFillColor(sf::Color::White);
  txtRanking.setPosition(btnRanking.getPosition().x + 25.f,
                         btnRanking.getPosition().y + 12.f);

  // Configuração do Botão Quit (Sair)
  btnQuit.setSize(sf::Vector2f(200.f, 50.f));
  btnQuit.setFillColor(sf::Color::Red);
  btnQuit.setPosition(
      sf::Vector2f(posX / 2, btnLevel1.getPosition().y + 300.f));

  txtQuit.setFont(font);
  txtQuit.setString("Quit/Sair :C");
  txtQuit.setCharacterSize(20);
  txtQuit.setFillColor(sf::Color::White);
  txtQuit.setPosition(btnQuit.getPosition().x + 25.f,
                      btnQuit.getPosition().y + 12.f);

  std::cout << "Menu Inicializado com botoes de mouse." << std::endl;
}

Menu::~Menu() {}

bool Menu::isMouseOver(const sf::RectangleShape& button,
                       const sf::RenderWindow& window) {
  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
  sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
  return button.getGlobalBounds().contains(mousePosF);
}

void Menu::execute() { update(); }

void Menu::processEvents(const sf::Event& event) {
  sf::RenderWindow* window = pGM->getWindow();
  if (window) {
    if (event.type == sf::Event::MouseButtonPressed) {
      if (event.mouseButton.button == sf::Mouse::Left) {
        if (isMouseOver(btnLevel1, *window)) {
          pGame->changeState(new ForestLevelState());
        } else if (isMouseOver(btnLevel2, *window)) {
          pGame->changeState(new ExtinctionLevelState());
        }
        // else if (isMouseOver(btnRanking, *window))
        //{
        //     Ranking* rankingState = new Ranking();
        //     //em caso do player morrer ou vencer o jogo
        //     //rankingState->setPlayer(&player1, player1.getScore());
        //     rankingState->setPlayer(NULL, 0);
        //     pGame->changeState(rankingState);
        // }
        else if (isMouseOver(btnQuit, *window)) {
          pGM->close();
        }
      }
    }
  } else {
    return;
  }
  ////1 vai para nível 1
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
  //	pGame->changeState(new ForestLevelState());
  ////2 vai para nivel 2
  // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
  //	pGame->changeState(new ExtinctionLevelState());
}

void Menu::update() {
  // lógica para mover cursor no menu
  sf::RenderWindow* window = pGM->getWindow();
  if (window) {
    if (isMouseOver(btnLevel1, *window))
      btnLevel1.setFillColor(sf::Color(0, 100, 0));
    else
      btnLevel1.setFillColor(sf::Color::Green);

    if (isMouseOver(btnLevel2, *window))
      btnLevel2.setFillColor(sf::Color(200, 0, 0));
    else
      btnLevel2.setFillColor(sf::Color::Red);
    if (isMouseOver(btnRanking, *window))
      btnRanking.setFillColor(sf::Color(0, 0, 100));
    else
      btnRanking.setFillColor(sf::Color::Blue);
    if (isMouseOver(btnQuit, *window))
      btnQuit.setFillColor(sf::Color(200, 0, 0));
    else
      btnQuit.setFillColor(sf::Color::Red);
  } else {
    std::cout << "window nulo em update no menu" << std::endl;
  }
}

void Menu::render() {
  float posX = float(pGM->getWindowSize().x) / 2;
  float posY = float(pGM->getWindowSize().y) / 2;
  pGM->updateCameraPos({posX, posY});
  // desenha menu
  sf::RenderWindow* window = pGM->getWindow();
  if (window) {
    window->draw(txtTitle);
    window->draw(btnLevel1);
    window->draw(txtLevel1);
    window->draw(btnLevel2);
    window->draw(txtLevel2);
    window->draw(btnRanking);
    window->draw(txtRanking);
    window->draw(btnQuit);
    window->draw(txtQuit);
  } else {
    std::cout << "window nulo em render no menu" << std::endl;
  }
}
