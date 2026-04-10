#include "Game.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <ctime>

Game::Game() : 
    width(1366),
	height(768),
    mWindow(sf::VideoMode({width, height}), "JOGO MYTO BOM"),
    mPlayer(mPlayerTexture)
{
  mPlayerTexture.loadFromFile("media/Massospondylus_idle_spritesheet.png");
}

void Game::run() {

  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (mWindow.isOpen()) {
    processEvents();
    timeSinceLastUpdate += clock.restart();

    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      processEvents();
      update(timePerFrame);
    }
    render();
  }
}

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
void Game::update(sf::Time dt) { mPlayer.update(dt); }

void Game::render() {
  mWindow.clear();
  mPlayer.draw(mWindow);
  mWindow.display();
}
