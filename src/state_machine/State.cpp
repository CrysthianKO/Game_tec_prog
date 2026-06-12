#include "state_machine/State.hpp"

State::State() : pGame(NULL), stateClock(), timeInState(0.0f)
{
}

State::~State()
{
}

void State::updateTime()
{
	timeInState = stateClock.getElapsedTime().asSeconds();
}

void State::setGameContext(Game* game)
{
	pGame = game;
}