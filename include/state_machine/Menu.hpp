#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include "state_machine/State.hpp"
//#include "Game.hpp"
//#include "state_machine/Ranking.hpp"
//#include "state_machine/ForestLevelState.hpp"
//#include "state_machine/ExtinctionLevelState.hpp"
#include "entities/Ente.hpp"
class Game;
class Menu :
	public State, public Ente
{
private:
	//justo deixar pGame em State no caso
	int selectedOption;
	sf::Font font;
	sf::Text txtTitle;
	sf::RectangleShape btnLevel1;
	sf::RectangleShape btnLevel2;
	sf::RectangleShape btnRanking;
	sf::RectangleShape btnQuit;
	sf::Text txtLevel1;
	sf::Text txtLevel2;
	sf::Text txtRanking;
	sf::Text txtQuit;
private:
	bool isMouseOver(const sf::RectangleShape& button, const sf::RenderWindow& window);
public:
	Menu();
	virtual ~Menu();
	void execute();
	void processEvents(const sf::Event& event);
	void update();
	void render();
};
