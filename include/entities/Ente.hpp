#pragma once
#include <SFML/Graphics.hpp>

namespace DinoGame {

namespace Managers {
class GraphicsManager;
class TimeManager;
}  // namespace Managers

class Ente {
 protected:
  int mId;
  static int cont_id;
  static Managers::GraphicsManager* pGM;
  static Managers::TimeManager* pTM;

 public:
  Ente();
  virtual ~Ente();

  virtual void execute() = 0;
  void static setGM(Managers::GraphicsManager* pG);
  void static setTM(Managers::TimeManager* pT);
  int getId() const;
};
}  // namespace DinoGame
