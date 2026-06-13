//#include "state_machine/ExtinctionLevelState.hpp"
//#include "managers/CollisionManager.hpp"
//#include "Game.hpp"
//#include "entities/characters/Player.hpp"
//#include "levels/ExtinctionLevel.hpp"
//
//ExtinctionLevelState::ExtinctionLevelState() : State(), player1(), pGM(GraphicsManager::getInstance()),
//pCM(CollisionManager::getInstance())
//{
//	pCM->includePlayer(&player1);
//}
//
//ExtinctionLevelState::~ExtinctionLevelState()
//{
//	pCM->clearComponents();
//}
//
//void ExtinctionLevelState::processEvents(const sf::Event& event)
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//		player1.handleInput(sf::Keyboard::Left, true);
//	//sf::Event event;
//	switch (event.type)
//	{
//	case sf::Event::KeyPressed:
//		// input do usuário true
//		player1.handleInput(event.key.code, true);
//		break;
//	case sf::Event::KeyReleased:
//		// input do usuário false
//		player1.handleInput(event.key.code, false);
//		break;
//	}
//	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//	//	pGame->changeState(new Menu());
//}
//
//void ExtinctionLevelState::update()
//{
//	player1.execute();
//	level2.execute();
//	pCM->execute();
//}
//
//void ExtinctionLevelState::render()
//{
//	//level2.draw();
//	level2.render();
//	player1.draw();
//}
