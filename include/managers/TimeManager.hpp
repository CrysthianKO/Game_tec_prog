#pragma once
#include "SFML/System/Clock.hpp"
namespace DinoGame {
namespace Managers {

class TimeManager {
 private:
  sf::Clock mClock;
  float mDeltaTime;
  static TimeManager* instance;

 protected:
  TimeManager();
  TimeManager(const TimeManager&) = delete;
  void operator=(const TimeManager&) = delete;

 public:
  static TimeManager* getInstance();

  void updateClock();
  float getDeltaTime() const;
};

}  // namespace Managers
}  // namespace DinoGame
