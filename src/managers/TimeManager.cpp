#include "managers/TimeManager.hpp"

#include <iostream>

namespace DinoGame {
namespace Managers {

using namespace std;
TimeManager* TimeManager::instance = NULL;

TimeManager::TimeManager() : mDeltaTime(0.f) {
  cout << "Clock criado!" << endl;
}
TimeManager* TimeManager::getInstance() {
  if (!instance) {
    instance = new TimeManager();
  }
  return instance;
}

void TimeManager::updateClock() { mDeltaTime = mClock.restart().asSeconds(); }
float TimeManager::getDeltaTime() const { return mDeltaTime; }

}  // namespace Managers
}  // namespace DinoGame
