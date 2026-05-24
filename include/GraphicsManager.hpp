#pragma once
#include <map>
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "Ente.hpp"
#include "ResourceType.hpp"
#include "ResourceManager.hpp"
#include "Camera.hpp"

class Ente; //Ente inclui GraphicsManeger (include circular)

class GraphicsManager {
public:
	static const unsigned int virtualWidth = 320;
	static const unsigned int virtualHeight = 180;

private:
	sf::RenderWindow mWindow; //singleton aqui

public:
	GraphicsManager();
	GraphicsManager(unsigned int width, unsigned int height);
	~GraphicsManager();

	bool isOpen() const;
	void close();
	//sfml 3.0 exige isso ai
	bool pollEvent(const std::function<void(const sf::Event&)>& eventHandler);

	void setFrameLimit(unsigned int limit);

	sf::Vector2u getVirtualSize() const;
	sf::Vector2u getWindowSize() const;

	Camera& getCamera();

	bool loadTexture(TextureId id, const std::string& filename);
	sf::Texture* getTexture(TextureId id);
	void clearTextures();
	
	//recebe ponteiro de Ente para desenhar
	//void drawEnte(Ente* pEnte);

	//inicia o frame, limpando a tela com a cor especificada (padrão preto)
	void beginFrame(const sf::Color& clearColor = sf::Color::Black);
	//parametros: objeto desenhado, camada e textura
	void submitDrawable(const sf::Drawable* drawable, int layer = 0,
						const sf::RenderStates& states = sf::RenderStates::Default);
	//finaliza o frame, desenhando os objetos submetidos e exibindo a janela
	void endFrame();

private:
	//Fila de desenhaveis, para desenhar em ordem de camadas (background atras das entidades)
	struct DrawableQueue {
		const sf::Drawable* drawable;
		//para aplicar transformações, texturas, shaders(opcional), etc. 
		sf::RenderStates states;
	};
	
	//aplica a ordem dos drawables, para desenhar em camadas
	void queueFlush();
	//atualiza os fatores de escala e offset para manter a proporção do conteúdo do RenderTexture na janela
	void updateScale();

private:
	//mapa de camadas, cada camada tem uma fila de drawables
	std::map<int, std::vector<DrawableQueue>> mDrawables;

	Camera mCamera;

	ResourceManager<sf::Texture, TextureId> mTextureHolder;

	//RenderTexture para desenhar em off-screen e depois exibir na janela, parte reescalada para manter a proporção
	sf::RenderTexture mRenderTexture;
	//sprite para desenhar o conteúdo do RenderTexture na janela
	sf::Sprite mRenderSprite;

	//fatores de escala e offset para ajustar o conteúdo do RenderTexture à janela ???
	float mScaleFactor;
	sf::Vector2f mOffset;
};