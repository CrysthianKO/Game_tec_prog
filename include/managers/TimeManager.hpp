#pragma once
#include "SFML/System/Clock.hpp"

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
