#include "Game.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <ctime>

Game::Game() : mWindow(sf::VideoMode({640, 480}), "JOGO MYTO BOM"), mPlayer() {}

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
  sf::Event event;
  while (mWindow.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::KeyPressed:
        mPlayer.handleInput(event.key.code, true);
        break;
      case sf::Event::KeyReleased:
        mPlayer.handleInput(event.key.code, false);
        break;
      case sf::Event::Closed:
        mWindow.close();
        break;
    }
  }
}
void Game::update(sf::Time dt) { mPlayer.update(dt); }

void Game::render() {
  mWindow.clear();
  mPlayer.draw(mWindow);
  mWindow.display();
}
