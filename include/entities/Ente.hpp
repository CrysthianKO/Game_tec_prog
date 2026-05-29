#pragma once
#include <SFML/Graphics.hpp>

#include "managers/GraphicsManager.hpp"

class Ente {
 protected:
  int mId;
  static int cont_id;
  static GraphicsManager* pGM;

 public:
  Ente();
  virtual ~Ente();

  virtual void execute() = 0;
  void static setGM(GraphicsManager* pG);
  int getId() const;
};
