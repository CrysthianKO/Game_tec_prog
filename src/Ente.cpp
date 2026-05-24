#include "Ente.hpp"

int Ente::cont_id = 0;
GraphicsManager* Ente::pGM = NULL;

Ente::Ente() : mId(cont_id++), mSprite(NULL) {

}

Ente::Ente(const sf::Texture& texture) : mId(cont_id++), mSprite(new sf::Sprite(texture)) {

}

Ente::~Ente(){
	if (mSprite) {
		delete mSprite;
		mSprite = NULL;
	}
}

int Ente::getId() const{
	return mId;
}

void Ente::setId(int id){
	mId = id;
}

//desenha o própio Ente usando o GraphicsManager, que é responsável por desenhar os Entes na janela do jogo
//void Ente::draw(){
//	if (pGM) {
//		pGM->drawEnte(this);
//	}
//}

void Ente::setGraphicsManager(GraphicsManager* pG){
	pGM = pG;
}
