#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include "SFML/Graphics/Rect.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <ctime>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <iterator>

#include "Player.hpp"
#include "Bone.hpp"
#include "Physics.hpp"

class Game {
 public:
     Game();
     ~Game();
     void run();
     void addScore(Bone* bone);
 private:
     void processEvents();
     void update(sf::Time dt);
     void render();
 private:
	 unsigned int width;
	 unsigned int height;
	 sf::Texture mPlayerTexture;
	 Player mPlayer;
	 Bone mCurrentBone;
	 sf::RenderWindow mWindow;
	 const sf::Time timePerFrame;
	 int mScore;
	 sf::Font mFont;
	 std::optional<sf::Text> mScoreText; // Opcional, pois só existirá se a fonte carregar
};
