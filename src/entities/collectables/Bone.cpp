#include "Bone.hpp"

Bone::Bone() 
  : Collectable(),
	//mSprite(mTexture),
	mScoreValue(10),
	mAnimationTimer(sf::Time::Zero)
{
	//carrega a textura do osso
	if (!mTexture.loadFromFile("media/Bone_spritesheet.png")) {
		std::cout << "ERROR: COUL NOT LOAD FILE" << std::endl;
	}
	//garante que o sprite existe, se o ente não alocou-o
	if (mSprite == NULL) {
		mSprite = new sf::Sprite(mTexture);
	}
	
	mSprite->setTexture(mTexture);
	// Define o frame inicial (ajuste os valores conforme seu spritesheet)
	mCurrentFrame = sf::IntRect({ 0, 0 }, { 32, 32 });
	mSprite->setTextureRect(mCurrentFrame);

	respawn(); // Começa em um lugar aleatório
}

Bone::~Bone()
{

}

//gera uma posição aleatória para o osso dentro dos limites da janela
void Bone::respawn()
{
	float x = static_cast<float>(rand() % 770 + 15);
	float y = static_cast<float>(rand() % 570 + 15);
	mSprite->setPosition(sf::Vector2f(x, y));
}

//retorna o valor de pontuação do osso
int Bone::getScoreValue()
{
	return mScoreValue;
}

//atualiza o estado do osso, mas como ele é estático, não há nada para atualizar por enquanto
void Bone::update(sf::Time deltaTime)
{

}

//atualiza a animacao do bone, mudando o frame da sprite a cada 0.1 segundos (hard coded)
void Bone::updateAnimation(sf::Time deltaTime) {
	mAnimationTimer += deltaTime;
	if (mAnimationTimer >= sf::seconds(0.15f)) {
		mCurrentFrame.position.x += 32; // Largura do frame
		if (mCurrentFrame.position.x >= (32 * 4)) { // 4 é o total de frames
			mCurrentFrame.position.x = 0;
		}
		mSprite->setTextureRect(mCurrentFrame);
		mAnimationTimer = sf::Time::Zero;
	}
}

//desenha o osso na janela
void Bone::draw(GraphicsManager* window)
{
	window->submitDrawable(mSprite);
}

//retorna os limites do sprite do osso para detecção de colisão
sf::FloatRect Bone::getBounds() const
{
	return mSprite->getGlobalBounds();
}

CollectableType Bone::getCollectableType() const {
	return CollectableType::CT_BONE;
}