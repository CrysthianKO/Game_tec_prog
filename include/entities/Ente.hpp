#pragma once
#include <SFML/Graphics.hpp>

#include "managers/GraphicsManager.hpp"
#include "managers/TimeManager.hpp"

class Ente {
 protected:
  int mId;
  static int cont_id;
  static GraphicsManager* pGM;
  static TimeManager* pTM;

 public:
  Ente();
  virtual ~Ente();

  virtual void execute() = 0;
  void static setGM(GraphicsManager* pG);
  void static setTM(TimeManager* pT);
  int getId() const;
};
