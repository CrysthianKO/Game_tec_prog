#include "managers/TimeManager.hpp"

#include <iostream>

using namespace std;
TimeManager::TimeManager() : mDeltaTime(0.f) {
  cout << "Clock criado!" << endl;
}
TimeManager& TimeManager::getInstance() {
  static TimeManager instance;
  return instance;
}
void TimeManager::updateClock() { mDeltaTime = mClock.restart().asSeconds(); }
float TimeManager::getDeltaTime() const { return mDeltaTime; }
