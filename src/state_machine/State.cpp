#include "state_machine/State.hpp"

#include "Game.hpp"

namespace DinoGame {
namespace StateMachine {

State::State()
    : pGame(NULL), stateClock(), timeInState(0.0f), id(StateID::Unknown) {}

State::~State() {}

StateID State::getID() const { return id; }

void State::updateTime() {
  timeInState = stateClock.getElapsedTime().asSeconds();
}

void State::setGameContext(Game* game) { pGame = game; }

}  // namespace StateMachine
}  // namespace DinoGame
