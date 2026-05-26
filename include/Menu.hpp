#pragma once
#include <SFML/Graphics.hpp>

#include "Ente.hpp"
#include "Game.hpp"

class Menu : public Ente {
 private:
  Game* pGame;

 public:
  Menu();
  ~Menu();
  void execute();
};
