#include "GraphicsManager.hpp"
#include "Ente.hpp"

GraphicsManager::GraphicsManager() 
  : width(1366), 
	height(768),
	mWindow(sf::VideoMode({width, height}), "Dino Game") {
	
}

GraphicsManager::~GraphicsManager(){
}

void GraphicsManager::drawEnte(Ente* pEnte){
	if (pEnte && pEnte->mSprite) {
		mWindow.draw(*pEnte->mSprite);
	}
}
