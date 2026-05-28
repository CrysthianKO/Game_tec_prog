#pragma once
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "entities/Ente.hpp"

class Menu : public Ente {
 private:
  Game* pGame;

 public:
  Menu();
  ~Menu();
  void execute();
};
