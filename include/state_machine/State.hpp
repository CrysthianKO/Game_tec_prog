#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
// #include "state_machine/Menu.hpp"
class Game;

enum class StateID {
	Unknown,
	Menu,
	Ranking,
	ForestLevel,
	ExtinctionLevel
};

class State {
 protected:
  Game* pGame;
  sf::Clock stateClock;
  float timeInState;
  StateID id;

 public:
  State();
  virtual ~State();
  StateID getID() const;
  void updateTime();
  virtual void setGameContext(Game* game);
  virtual void processEvents(const sf::Event& event) = 0;
  virtual void update() = 0;
  virtual void render() = 0;
};
