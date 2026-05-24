#include "GraphicsManager.hpp"
#include "Ente.hpp"

GraphicsManager::GraphicsManager() : mWindow(), mRenderTexture(), mRenderSprite(mRenderTexture.getTexture())
{
	
}

GraphicsManager::GraphicsManager(unsigned int width, unsigned int height)
  : mWindow(sf::VideoMode({width, height}), "Dino Game"),
    mScaleFactor(1.0f),
    mOffset(0.0f, 0.0f),
	mRenderTexture(),
	mRenderSprite(mRenderTexture.getTexture())
{
	mRenderTexture.resize({virtualWidth, virtualHeight});
	mRenderTexture.setSmooth(false); // Evita suavização para manter a pixel art nítida
	
	mRenderSprite.setTexture(mRenderTexture.getTexture());
	mRenderSprite.setTextureRect(sf::IntRect({0, 0}, {virtualWidth, virtualHeight}));
	updateScale();
}

GraphicsManager::~GraphicsManager()
{

}

bool GraphicsManager::isOpen() const
{
	return mWindow.isOpen();
}

void GraphicsManager::close()
{
	mWindow.close();
}

bool GraphicsManager::pollEvent(const std::function<void(const sf::Event&)>& eventHandler)
{
	while (const auto event = mWindow.pollEvent()) { //trocar auto
		//auto e = event;
		//if (e) {
		//	event = *e;
		//	return true;
		//}
		eventHandler(*event);
	}
	//return false;
}

void GraphicsManager::setFrameLimit(unsigned int limit)
{
	mWindow.setFramerateLimit(limit);
}

sf::Vector2u GraphicsManager::getVirtualSize() const
{
	return sf::Vector2u();
}

sf::Vector2u GraphicsManager::getWindowSize() const
{
	return sf::Vector2u();
}

Camera& GraphicsManager::getCamera()
{
	return mCamera;
}

bool GraphicsManager::loadTexture(TextureId id, const std::string& filename)
{
	return mTextureHolder.load(id, filename);
}

sf::Texture* GraphicsManager::getTexture(TextureId id)
{
	if (!mTextureHolder.exists(id)) {
		std::cout << "Texture with ID " << static_cast<int>(id) << " not found." << std::endl;
		return NULL;
	}
	return mTextureHolder.get(id);
}

//void GraphicsManager::drawEnte(Ente* pEnte){
//	if (pEnte && pEnte->mSprite) {
//		mWindow.draw(*pEnte->mSprite);
//	}
//}

void GraphicsManager::beginFrame(const sf::Color& clearColor)
{
	mDrawables.clear();
	mRenderTexture.setView(mCamera.getView(getVirtualSize()));
	mRenderTexture.clear(clearColor);
}

void GraphicsManager::submitDrawable(const sf::Drawable* drawable, int layer, const sf::RenderStates& states)
{
		mDrawables[layer].push_back({drawable, states});
}

void GraphicsManager::endFrame()
{
	queueFlush();
	mRenderTexture.display();
	mWindow.clear();
	updateScale();
	mWindow.draw(mRenderSprite);
	mWindow.display();
}

void GraphicsManager::queueFlush()
{
	std::map<int, std::vector<DrawableQueue>>::iterator it = mDrawables.begin();
	
	while (it != mDrawables.end()) {
		for (const auto& queue : it->second) { //trocar para c++2003
			mRenderTexture.draw(*queue.drawable, queue.states);
		}
		++it;
	}
}

//lógica para calcular os fatores de escala e offset com base no tamanho da janela e do conteúdo virtual, 
// garantindo que o conteúdo seja centralizado e mantenha a proporção correta, mesmo que a janela seja redimensionada
void GraphicsManager::updateScale()
{
	sf::Vector2u windowSize = mWindow.getSize();
	sf::View view(sf::FloatRect({ 0.f, 0.f }, {static_cast<float>(windowSize.x), static_cast<float>(windowSize.y)}));
	mWindow.setView(view);

	float scaleX = static_cast<float>(windowSize.x) / virtualWidth;
	float scaleY = static_cast<float>(windowSize.y) / virtualHeight;
	float newScale = (scaleX > scaleY) ? scaleX : scaleY;

	if (newScale <= 0.f) {
		newScale = 1.f; // Evita divisão por zero ou escala negativa
	}

	float scaledWidth = virtualWidth * newScale;
	float scaledHeight = virtualHeight * newScale;

	mOffset.x = (windowSize.x - scaledWidth) / 2.f;
	mOffset.y = (windowSize.y - scaledHeight) / 2.f;

	mRenderSprite.setScale({newScale, newScale});
	mRenderSprite.setPosition(mOffset);
}
