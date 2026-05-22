#pragma once
#include <SFML/Graphics.hpp>
#include <GraphicsManager.hpp>

class GraphicsManager; //evitar include circular

class Ente {
protected:
	int mId;
	static int cont_id;
	static GraphicsManager* pGM;
public:
	sf::Sprite* mSprite; //singleton
public:
	Ente();
	Ente(const sf::Texture& texture);
	virtual ~Ente();
	virtual int getId() const;
	virtual void setId(int id);
	virtual void draw();
	static void setGraphicsManager(GraphicsManager* pG);
};