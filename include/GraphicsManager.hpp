#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.hpp"

class Ente; //Ente inclui GraphicsManeger (include circular)

class GraphicsManager {
private:
	unsigned int width;
	unsigned int height;
public:
	sf::RenderWindow mWindow; //singleton aqui
public:
	GraphicsManager();
	~GraphicsManager();
	//recebe ponteiro de Ente para desenhar
	void drawEnte(Ente* pEnte);
};